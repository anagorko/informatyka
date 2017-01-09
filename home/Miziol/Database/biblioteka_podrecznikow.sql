USE biblioteka_podrecznikow

DROP TABLE IF EXISTS studenci;

CREATE TABLE studenci
	(
	pesel BIGINT,
	nazwisko CHAR(100),
	imie CHAR(100)
	);

LOAD DATA LOCAL INFILE 'studenci.txt' INTO TABLE studenci IGNORE 1 LINES;

DROP TABLE IF EXISTS meldunek;

CREATE TABLE meldunek
	(
	pesel BIGINT,
	id_pok INT
	);

LOAD DATA LOCAL INFILE 'meldunek.txt' INTO TABLE meldunek IGNORE 1 LINES;

DROP TABLE IF EXISTS wypozyczenia;

CREATE TABLE wypozyczenia
	(
	lp INT,
	pesel BIGINT,
	tytul CHAR (255)
	);

LOAD DATA LOCAL INFILE 'wypozyczenia.txt' INTO TABLE wypozyczenia IGNORE 1 LINES;



SELECT imie, nazwisko, COUNT(tytul) AS ile
FROM studenci, wypozyczenia
WHERE studenci.pesel = wypozyczenia.pesel
GROUP BY studenci.pesel
ORDER BY ile DESC
LIMIT 1 \G

SELECT avg( count(pesel) )
FROM meldunek
GROUP BY id_pok \G

SELECT plec, COUNT( plec ) AS ile
FROM (
	SELECT imie, nazwisko, MOD( FLOOR( MOD( pesel, 100) /10 ), 2 ) AS plec
	FROM studenci ) sex
GROUP BY plec \G

SELECT imie, nazwisko
FROM studenci, meldunek
WHERE studenci.pesel NOT EXISTS( meldunek.pesel)
ORDER BY nazwisko \G