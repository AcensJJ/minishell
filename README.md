# minishell

![Screenshot 2020-10-21_19-05-33-326](https://user-images.githubusercontent.com/45235527/96753610-698e7080-13d0-11eb-9461-d3351c9208d7.png)

Description

L'objectif de ce projet est de créer un simple shell.

Project en collaboration avec <a href="https://github.com/ereynier">Estéban Reynier</a> <a href="https://profile.intra.42.fr/users/ereynier">ereynier</a>.


# Partie Obligatoire

![Capture](https://user-images.githubusercontent.com/45235527/96900125-09600300-1492-11eb-9e2a-39831a49f01d.PNG)

Votre shell doit :

- Afficher un prompt en l’attente d’une nouvelle commande
- Chercher et lancer le bon executable (basé sur une variable d’environnement PATH ou en utilisant un path absolu), comme dans bash
- Vous devez implémenter les builtins suivants :
  - echo et l’option ’-n’
  - cd uniquement avec un chemin absolu ou relatif
  - pwd sans aucune option
  - export sans aucune option
  - unset sans aucune option
  - env sans aucune option ni argument
  - exit sans aucune option
- ; dans la ligne de commande doit séparer les commandes
- ’ et " doivent marcher comme dans bash, à l’exception du multiligne.
- Les redirections <, > et “>>” doivent marcher comme dans bash, à l’exception des aggrégations de fd
- Pipes | doivent marcher comme dans bash
- Les variables d’environnement ($ suivi de caractères) doivent marcher comme dans bash.
- $? doit marcher comme dans bash
- ctrl-C, ctrl-D et ctrl-\ doivent afficher le même résultat que dans bash.
