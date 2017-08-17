[![Build Status](https://travis-ci.com/Alkass/Flint.svg?token=5HdMqhthhyUjijBZQvCS&branch=master)](https://travis-ci.com/Alkass/Flint)

# Flint
Flint is a drone firmware designed with hackability and extensibility in mind.

# Story Behind this Creation
Most drone firmware come with proprietary communication protocols and no SDK. We've had our course with poking holes into existing firmwares and thought there has to be an easier way to control a drone from the comfort of one's computer. Unfortunately, it turns out there hasn't, so we decided to invent a firmware from the ground up with hackability in mind.

We realize that the drone market is still living its infancy days, which means things will get added and others will change. So, we decided to have an architecture capable of adapting to additions and changes.

There you have the story. Interested? Consider contributing. The project is fairly new and we're sure we can squeeze you in somewhere and suck the life out of you. Just make sure you conform to our coding standards <b>which are yet to be added</b>, and you're good to go.

# Getting Started
## Deploying to the Pi
1. Create an application on [resin.io](https://resin.io) and download RESINOS to your board. Instructions are available [here](https://docs.resin.io/raspberrypi3/cpp/getting-started/) if you've never done this before.
2. Check out this repository:
```shell
  git clone https://github.com/alkass/Flint.git && cd Flint
```
3. Add the application's Git remote endpoint to the checkout out repo:
```shell
  git remote add resin <username>@git.resin.io:<username>/<app name>.git
```
That's it. You should now be able to see a 'Downloading' progress bar under your application.

## Building the Source Code
```shell
  vagrant up # only once per repository check out
  vagrant provision # install all that's necessary for the build to succeed
  vagrant ssh
  make # build a debug version of the code
  make run # or 'make analyze' to run the build against Valgrind for memory leak checks
```

## Contributing
Submit your contributions as pull requests. Make sure you have run `make && make analyze` prior to submitting your PR. contributions with leaks will break the build. PR that breaks the build won't get approved.

# Author
[Fadi Hanna Al-Kass](https://github.com/alkass)
