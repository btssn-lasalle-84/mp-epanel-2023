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
