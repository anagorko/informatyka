USE dziennik_ocen

DROP TABLE IF EXIST uczniowie
CREATE TABLE uczniowie(
	VARCHAR(8) id_ucznia,
	VARCHAR(100) imie,
	VARCHAR(100) nazwisko,
	VARCHAR(4) klasa

);

LOAD DATA LOCAL INFILE uczniowie.txt INTO TABLE uczniowie IGNORE 1 LINES;

DROP TABLE IF EXIST przedmioty
CREATE TABLE przedmioty(
	INT id_przedmiotu,
	VARCHAR(100) nazwa_przedmiotu
);

LOAD DATA LOCAL INFILE przedmioty.txt INTO TABLE przedmioty IGNORE 1 LINES;

DROP TABLE IF EXIST oceny
CREATE TABLE oceny(
	INT id_oceny,
	DATA data,
	VARCHAR(8) id_ucznia,
	INT id_przedmiotu,
	INT ocena
);

LOAD DATA LOCAL INFILE oceny.txt INTO TABLE oceny IGNORE 1 LINES;

SELECT klasa
FROM uczniowie
WHERE 