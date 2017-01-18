USE dziennik_ocen

DROP TABLE IF EXISTS uczniowie;
CREATE TABLE uczniowie
	(
	id_ucznia CHAR(8),
	imie CHAR(100),
	nazwisko CHAR(100),
	klasa CHAR(4)
	);

LOAD DATA LOCAL INFILE 'uczniowie.txt' INTO TABLE uczniowie LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS przedmioty;
CREATE TABLE przedmioty
	(
	id_przedmiotu INT,
	nazwa_przedmiotu CHAR(100)
	);

LOAD DATA LOCAL INFILE 'przedmioty.txt' INTO TABLE przedmioty LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS oceny;
CREATE TABLE oceny
	(
	id_oceny INT,
	data DATE,
	id_ucznia CHAR(8),
	id_przedmiotu INT,
	ocena INT
	);

LOAD DATA LOCAL INFILE 'oceny.txt' INTO TABLE oceny LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

SELECT ile_d.klasa
FROM 
	(SELECT klasa, COUNT( imie ) as d FROM uczniowie WHERE imie LIKE '%a' GROUP BY klasa) as ile_d,
	(SELECT klasa, COUNT( imie ) as m FROM uczniowie WHERE imie NOT LIKE '%a' GROUP BY klasa) ile_m
WHERE ile_d.klasa = ile_m.klasa AND ile_d.d > ile_m.m;

SELECT data
FROM
	(SELECT data, COUNT( * ) as ile
	FROM oceny
	WHERE ocena = 1
	GROUP BY data ) as jedynki
WHERE ile > 10;

SELECT klasa, ROUND( AVG(ocena) , 2 ) as srednia
FROM uczniowie, przedmioty, oceny
WHERE uczniowie.id_ucznia = oceny.id_ucznia AND przedmioty.id_przedmiotu = oceny.id_przedmiotu
	AND nazwa_przedmiotu LIKE 'j.polski' AND klasa LIKE 'IV%'
GROUP BY klasa;

SELECT nazwa_przedmiotu, month(data) as miesiac, COUNT( * )
FROM przedmioty, oceny
WHERE przedmioty.id_przedmiotu = oceny.id_przedmiotu
	AND ocena = 5
GROUP BY nazwa_przedmiotu, miesiac;

SELECT imie, nazwisko
FROM uczniowie, oceny, przedmioty
WHERE oceny.id_przedmiotu = przedmioty.id_przedmiotu AND uczniowie.id_ucznia = oceny.id_ucznia
AND klasa LIKE 'II A' AND id_przedmiotu LIKE 'sieci komputerowe%'
AND uczniowie.id_ucznia NOT EXISTS( oceny.id_ucznia)
ORDER BY nazwisko;