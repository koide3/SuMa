// qt5 based visualization application using core.
#include <core/SurfelMapping.h>
#include <glow/glbase.h>
#include "VisualizerWindow.h"

#include <rv/FileUtil.h>
#include <rv/PrimitiveParameters.h>
#include <rv/Stopwatch.h>

#include <locale>
#include <boost/program_options.hpp>

using namespace rv;

int main(int argc, char** argv) {
  using namespace boost::program_options;
  options_description description("SuMa options");
  description.add_options()
  ("help", "produce help message")
  ("config", value<std::string>()->default_value("../config/default.xml"), "config parameter file")
  ("dataset", value<std::string>(), "KITTI dataset")
  ("play,p", "if auto play the dataset")
  ("save,s", value<std::string>(), "destination filename of estimated pose data")
  ("background,b", "do not show window")
  ("quit,q", "quit when playback finished")
  ;

  positional_options_description p;
  p.add("config", 1);
  p.add("dataset", 2);

  variables_map vm;
  store(command_line_parser(argc, argv).
  options(description).
  positional(p).
  run(), vm);
  notify(vm);

  if(vm.count("help")) {
    std::cout << description << std::endl;
    return 0;
  }

  QApplication app(argc, argv);

  setlocale(LC_NUMERIC, "C");

  VisualizerWindow window;  // generates the OpenGL context...

  // initialize Laser Fusion.
  rv::ParameterList params;  // default parameters.
  if (!vm.count("config")) {
    parseXmlFile("../config/default.xml", params);
  } else {
    parseXmlFile(vm["config"].as<std::string>(), params);
  }

  std::shared_ptr<SurfelMapping> fusion = std::shared_ptr<SurfelMapping>(new SurfelMapping(params));

  window.initialize(fusion, params);

  if(!vm.count("background")) {
    window.show();
  }

  // open file:
  if (vm.count("dataset")) {
    std::string dataset = vm["dataset"].as<std::string>();
    std::cout << "Opening " << dataset << std::endl;
    window.openFile(QString(dataset.c_str()));
  }

  if(vm.count("play")) {
    window.play(true);
  }

  if(vm.count("save")) {
    std::string dst_filename = vm["save"].as<std::string>();
    std::cout << "Save poses to " << dst_filename << std::endl;
    window.setPoseDestination(dst_filename);
  }

  if(vm.count("quit")) {
    std::cout << "Quit at finish" << std::endl;
    window.setQuitAtFinish(true);
  }

  int32_t ret = app.exec();

  std::cout << rv::Stopwatch::active() << " stopwatches active at exit." << std::endl;

  return ret;
}
