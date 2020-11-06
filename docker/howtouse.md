# SuMa

Original repository: https://github.com/jbehley/SuMa

## Build
```bash
cd suma/docker
./build.sh
```

## Run

### On docker image:
```bash
cd suma/docker
./run.sh -v ~/kitti:/kitti

./visualizer ../config/default.xml /kitti/sequences/00/velodyne/000000.bin -p
```

KITTI: http://www.cvlibs.net/datasets/kitti/
