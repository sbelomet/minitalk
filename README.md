# 📣 minitalk 📣

`ca talk mais de facon tres mini`

### Resources utiles

**📚 [`GITBOOK`](https://42-cursus.gitbook.io/guide/rank-02/minitalk) 📚** - Gitbook pour minitalk

## 

### Ce qu'il faut faire

Un programme "client" qui envoie des messages à un programme "serveur" à l'aide de deux signaux UNIX (`SIGUSR1` et `SIGUSR2`)

Le gitbook explique bien comment faire alors clique dessus 😘

### Pour me voler le mien

1. `make && make bonus`
2. `./minitalk/server` dans un terminal pour lancer le serveur
3. `./minitalk/client <PID du serveur> <message>` dans un autre terminal pour envoyer un message au terminal
