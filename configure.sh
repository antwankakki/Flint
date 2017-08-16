apt-get -yq update
apt-get install -yq --no-install-recommends build-essential valgrind
apt-get clean
rm -rf /var/lib/apt/lists/*
