#!/bin/bash
xhost + local:root

docker run -it --rm \
			--gpus all \
			-e DISPLAY=$DISPLAY \
			-v /tmp/.X11-unix:/tmp/.X11-unix \
			-v $(realpath ../config):/root/catkin_ws/src/SuMa/config \
			-w /root/catkin_ws/src/SuMa/bin \
			$@ \
			suma

# xhost - local:root
