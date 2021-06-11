<p align="center">
    <img alt="42-lyon" src="https://user-images.githubusercontent.com/45235527/106354618-6ec65a00-62f3-11eb-8688-ba9e0f4e77de.jpg" />
</p>

# minishell

<img alt="Note" src="https://user-images.githubusercontent.com/45235527/96753610-698e7080-13d0-11eb-9461-d3351c9208d7.png" width="250" height="200" />

### <strong>Description</strong>

L'objectif de ce projet est de créer un simple shell.

> *Project en collaboration avec <a href="https://github.com/ereynier">Estéban Reynier</a> (<a href="https://profile.intra.42.fr/users/ereynier">ereynier</a>).*

<p align="center">
  <img alt="minishell" src="https://user-images.githubusercontent.com/45235527/104728925-edd66280-5737-11eb-9730-d3f94be6a5b6.gif" />
</p>

# Partie Obligatoire

![Sujet](https://user-images.githubusercontent.com/45235527/97051231-1b6b9f80-157f-11eb-9f2d-0962d44f0bc9.PNG)

Votre shell doit :

- Afficher un prompt en l’attente d’une nouvelle commande
- Chercher et lancer le bon executable (basé sur une variable d’environnement PATH ou en utilisant un path absolu), comme dans bash
- Vous devez implémenter les builtins suivants :
  - `echo` et l’option `’-n’`
  - `cd` uniquement avec un chemin absolu ou relatif
  - `pwd` sans aucune option
  - `export` sans aucune option
  - `unset` sans aucune option
  - `env` sans aucune option ni argument
  - `exit` sans aucune option
- <strong>;</strong> dans la ligne de commande doit séparer les commandes
- <strong>’</strong> et " doivent marcher comme dans bash, à l’exception du multiligne.
- Les redirections <strong><</strong>, <strong>></strong> et <strong>“>>”</strong> doivent marcher comme dans bash, à l’exception des aggrégations de fd
- Pipes <strong>|</strong> doivent marcher comme dans bash
- Les variables d’environnement `($ suivi de caractères)` doivent marcher comme dans bash.
- <strong>$?</strong> doit marcher comme dans bash
- `ctrl-C`, `ctrl-D` et `ctrl-\` doivent afficher le même résultat que dans bash.
