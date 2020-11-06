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

![suma](https://user-images.githubusercontent.com/31344317/98347890-60053980-205b-11eb-97fa-de73c2f9448f.gif)
