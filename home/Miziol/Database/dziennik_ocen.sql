USE dziennik_ocen

DROP TABLE IF EXISTS uczniowie;
CREATE TABLE uczniowie
	(
	id_ucznia CHAR(8),
	imie CHAR(100),
	nazwisko CHAR(100),
	klasa CHAR(4)
	);

LOAD DATA LOCAL INFILE 'uczniowie.txt' INTO TABLE uczniowie IGNORE 1 LINES;

DROP TABLE IF EXISTS przedmioty;
CREATE TABLE przedmioty
	(
	id_przedmiotu INT,
	nazwa_przedmiotu CHAR(100)
	);

LOAD DATA LOCAL INFILE 'przedmioty.txt' INTO TABLE przedmioty IGNORE 1 LINES;

DROP TABLE IF EXISTS oceny;
CREATE TABLE oceny
	(
	id_oceny INT,
	data DATE,
	id_ucznia CHAR(8),
	id_przedmiotu INT,
	ocena INT
	);

LOAD DATA LOCAL INFILE 'oceny.txt' INTO TABLE oceny IGNORE 1 LINES;

SELECT ile_d.klasa
FROM 
	(SELECT klasa, COUNT( imie ) as d FROM uczniowie WHERE imie LIKE '%a' GROUP BY klasa) as ile_d,
	(SELECT klasa, COUNT( imie ) as m FROM uczniowie WHERE imie NOT LIKE '%a' GROUP BY klasa) ile_m
WHERE ile_d.klasa = ile_m.klasa AND ile_d.d > ile_m.m \G