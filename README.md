[![Build Status](https://travis-ci.com/Alkass/Flint.svg?token=5HdMqhthhyUjijBZQvCS&branch=master)](https://travis-ci.com/Alkass/Flint)

# Flint
Flint is a drone firmware designed with hackability and extensibility in mind.

# Story Behind this Creation
Most drone firmware come with proprietary communication protocols and no SDK. We've had our course with poking holes into existing firmwares and thought there has to be an easier way to control a drone from the comfort of one's computer. Unfortunately, it turns out there hasn't, so we decided to invent a firmware from the ground up with hackability in mind.

We realize that the drone market is still living its infancy days, which means things will get added and others will change. So, we decided to have an architecture capable of adapting to additions and changes.

There you have the story. Interested? Consider contributing. The project is fairly new and we're sure we can squeeze you in somewhere and suck the life out of you. Just make sure you conform to our coding standards <b>which are yet to be added</b>, and you're good to go.

# Getting Started
## Deploying the Firmware to the Pi
```shell
# Create an application on [resin.io](https://resin.io) and download RESINOS
# to your board. Instructions are available at https://docs.resin.io/raspberrypi3/cpp/getting-started/
# if you've never done this before

# Check out the repository
git clone https://github.com/alkass/Flint.git && cd Flint

#  Add the application's Git remote endpoint to the repository
git remote add resin <username>@git.resin.io:<username>/<app name>.git

# That's it. You should now be able to see a 'Downloading' progress bar under your application.
```

## Building the Source Code
```shell
  # Check out the code repository
  git clone https://github.com/alkass/Flint.git && cd Flint
  
  # Skip this step if you already have vagrant installed on your machine
  chmod +x configure.sh && sudo ./configure.sh
  
  # Bring the Vagrant box up
  # You only need to run this operation once per check out
  vagrant up
  
  # Install all that's necessary for the build to succeed
  # Technically, you only need to run this once, but wouldn't 
  # hurt to run it every couple of days as provisioning may change
  # from release to release
  # Also, consider running this if the following command fails and you
  # haven't provisioned the box in a while
  vagrant provision
  
  # Connect to your box over SSH
  vagrant ssh
  
  # Build a debug version of the code
  # You may also run `make release` or `run production` if you're not
  # interested in seeing all that hairy debugging info
  # `make release` weeds out most of the low-level debug info
  # `make production` weeds out all debug logs
  make
  
  # This command runs your last build (anything generated from
  # `make debug`, `run release` or `run production`).
  # If you've run `make debug` from the previous step, you can run
  # `make analyze` to test the build against Valgrind and find all
  # possible memory leaks in the code
  make run
```

## Remote Control Specification
The Remote Control Specification allows you to control the drone over various TCP-based protocols. This specification is designed to allow high-level control (Drone takeoff/landing, movement, height, direction, speed, camera streaming, capturing scenes, battery status retrieval, etc) as well as low-level control (rotor thrust, GSP, etc) when properly connected.

We'll assume a pure TCP connection is established between the drone and your controller for the sake of simplicity, but this specification should work across all supported connections with little or no changes.

All commands sent to the drone consist of a list of 10 integer values. How the values are constructed and organized is discussed as you read further down.

TBC

## Contributing
* Submit your contributions as pull requests. Make sure you have run `make && make analyze` prior to submitting your PR. contributions with leaks will break the build. PRs that break the build will be rejected.

* When submitting a PR, clearly explain what has been done.

* Do NOT directly modify makefile, configure.sh, .travis.yml, Dockerfile.template, or Vagrantfile. If, for some reason, you need to introduce additions or changes to any of these files, start a GitHub issue.

* No dynamically loaded libraries.

# Authors & Contributors
## Authors
[Fadi Hanna Al-Kass](https://github.com/alkass)

## Contributors
