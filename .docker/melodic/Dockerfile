# This file expects to be run in the root of the project folder:
# docker build -t tylerjw/circle_ci_test-melodic:0.0.1 -f .docker/melodic/Dockerfile .
FROM ros:melodic-ros-base

# install apt dependencies
RUN apt-get update && apt-get install -qq \
      build-essential \
      ca-certificates \
      ccache \
      clang \
      clang-format-3.9 \
      clang-tidy \
      clang-tools \
      cmake \
      git \
      gzip \
      openssh-client \
      python-catkin-tools \
      python-vcstool \
      tar \
      wget \
    && rm -rf /var/lib/apt/lists/*

# install dependencies
RUN mkdir -p /opt/ros_ws/src
COPY . /opt/ros_ws/src/project
RUN . /opt/ros/$ROS_DISTRO/setup.sh && \
    wstool init --shallow /opt/ros_ws/src \
      /opt/ros_ws/src/project/upstream.rosinstall && \
    apt-get update && \
    rosdep install -q -y \
      --from-paths /opt/ros_ws/src \
      --ignore-src && \
    rm -rf /opt/ros_ws && \
    rm -rf /var/lib/apt/lists/*

RUN echo 'export PATH=/usr/lib/ccache:$PATH' >> /root/.bashrc
