# This file expects to be run in the root of the project folder:
# docker build -t tylerjw/circle_ci_test-melodic:0.0.1 -f .docker/melodic/Dockerfile .
FROM ros:melodic-ros-base

# install apt dependencies
RUN apt-get update && apt-get install -q -y \
      build-essential \
      cmake \
      git \
      wget \
      ccache \
      python-catkin-tools \
      clang \
      clang-format-3.9 \
      clang-tidy \
      clang-tools \
      gzip \
      tar \
      ca-certificates \
    && rm -rf /var/lib/apt/lists/*

# setup workspace
ENV ROS_WS /opt/ros_ws
RUN mkdir -p $ROS_WS/src
COPY . $ROS_WS/src/project

# install dependencies
RUN . /opt/ros/$ROS_DISTRO/setup.sh && \
    wstool init $ROS_WS/src \
      $ROS_WS/src/project/upstream.rosinstall && \
    apt-get update && \
    rosdep install -q -y \
      --from-paths $ROS_WS/src \
      --ignore-src && \
    rm -rf $ROS_WS && \
    rm -rf /var/lib/apt/lists/*
