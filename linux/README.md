
# General Linux

## Setting up GitHub

Generate a RSA key pair and add the public key to GitHub
```
 ssh-keygen -t rsa -b 4096
```

Install and configure GitHub
```
sudo apt-get install git
git config --global user.email "david@kilcyconsulting.com"
git config --global user.name "David Kilcy"
git config --global core.editor vi
```

Checkout repository: `git clone git@github.com:dkilcy/robotics-iot.git`

Commit data to GitHub
```
git add --all
git commit .
git push
```

Pull changes from GitHub: `git pull`

