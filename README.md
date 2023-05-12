# Mini-projet Epanel 2023

**Epanel** est un projet étudiant de 1°année de BTS SN visant à créer un panneau "journal lumineux" interactif. Le panneau affiche des noms de lieux-dits ainsi que leur direction, et peut être contrôlé via une application web.

## Technologies utilisées

Le projet utilise les technologies suivantes :

- HTML/CSS
- JavaScript
- PHP (Version 8.1.12)
- C++
- MariaDb 10.4.27 (via [XAMPP](https://www.apachefriends.org/fr/index.html))
- Apache 2.4.54 (via [XAMPP](https://www.apachefriends.org/fr/index.html))

## Fonctionnalités

Les principales fonctionnalités du panneau journal lumineux sont les suivantes :

- Affichage des noms de lieux-dits et de leur direction
- Contrôle du panneau via une application web
- Mise à jour dynamique des informations affichées sur le panneau

## Utilisation

Pour utiliser le journal lumineux*, il suffit de se connecter à l'application web correspondante et de contrôler le panneau à partir de l'interface utilisateur. Les mises à jour des informations affichées sont effectuées automatiquement et en temps réel.

> ***Fonctionne uniquement sur ©️ Microsoft Windows** pour cette version

## Mise en place Base de donnée

Pour créer la base de données, exécutez cette commande dans le terminal MySQL : ```source C:\chemin\vers\le\fichier.sql```

Ou importez-le dans phpMyAdmin.

Code SQL de la base de donnée :
```sql
-- Code exporter de la BDD PHPmyAdmin

-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Hôte : 127.0.0.1
-- Généré le : mar. 04 avr. 2023 à 10:30
-- Version du serveur : 10.4.27-MariaDB
-- Version de PHP : 8.1.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `e-panel`
--
CREATE DATABASE IF NOT EXISTS epanel;
USE epanel;
-- --------------------------------------------------------

--
-- Structure de la table `infopanneau`
--

CREATE TABLE `infopanneau` (
  `ID` int(11) NOT NULL,
  `Message` text NOT NULL,
  `Symbole` text NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Déchargement des données de la table `infopanneau`
--

INSERT INTO `infopanneau` (`ID`, `Message`, `Symbole`) VALUES
(1, 'Bus','->'),
(2, 'Metro','->'),
(3, 'Mcdo','->'),
(4, 'Cinema','->'),
(5, 'Mairie','->'),
(6, 'Ecole','->'),
(7, 'Piscine','->'),
(8, 'Republique','->');

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `infopanneau`
--
ALTER TABLE `infopanneau`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `infopanneau`
--
ALTER TABLE `infopanneau`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
```

## Captures
### ***Interface Home-Machine :***
![IHM-Web](https://github.com/btssn-lasalle-84/mp-epanel-2023/blob/23d1fa3511586dd38d147c9c5866f7780894c137/Epannel_2023-main/E-Panel1/IMG/IHM.png)
### ***Journal lumineux :***
![Journal-lumi](https://github.com/btssn-lasalle-84/mp-epanel-2023/blob/bd445b15d91aa16b73c6e51acf86d143ef8f93c5/Epannel_2023-main/E-Panel1/IMG/E-panel.gif)
## Auteurs

Ce projet a été réalisé par les étudiants suivants :

- HNIZDO Thomas (IR)
- MAURIN Logan (IR)
- BROUSSE Antoine (EC)

---
©️ LaSalle Avignon - 2023

