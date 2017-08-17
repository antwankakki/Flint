Vagrant.configure("2") do |config|
  config.vm.box = "hashicorp/precise64"
  config.vm.provision :shell, path: "configure.sh"
  config.vm.provision :shell, inline: "ln -sf /vagrant/* ~"
end
