USE dziennik_ocen;

DROP TABLE IF EXISTS uczniowie;

CREATE TABLE uczniowie(
id_ucznia VARCHAR(100),
imie VARCHAR(100),
nazwisko VARCHAR(100),
klasa VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/98/uczniowie.txt'
INTO TABLE uczniowie IGNORE 1 LINES;

DROP TABLE IF EXISTS przedmioty;

CREATE TABLE przedmioty(
id_przedmiotu INT,
nazwa_przedmiotu VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/98/przedmioty.txt'
INTO TABLE przedmioty IGNORE 1 LINES;

DROP TABLE IF EXISTS oceny;

CREATE TABLE oceny(
id_oceny INT,
data DATE,
id_ucznia VARCHAR(100),
id_przedmiotu INT,
ocena INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/98/oceny.txt'
INTO TABLE oceny IGNORE 1 LINES;

#98.1
/*
SELECT chlopaki.klasa
FROM	(SELECT COUNT(imie) AS ilosc, klasa
	FROM uczniowie
	WHERE imie NOT LIKE '%a'
	GROUP BY klasa) AS chlopaki
	JOIN
	(SELECT COUNT(imie) AS ilosc, klasa
	FROM uczniowie
	WHERE imie LIKE '%a'
	GROUP BY klasa) AS dziewczyny
WHERE chlopaki.klasa = dziewczyny.klasa
	AND chlopaki.ilosc < dziewczyny.ilosc;
*/

#98.2
/*
SELECT data
FROM  oceny
WHERE ocena = 1
GROUP BY data
HAVING COUNT(ocena) > 10;
*/

#98.3

