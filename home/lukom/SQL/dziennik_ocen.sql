USE dziennik_ocen;

DROP TABLE IF EXISTS uczniowie;

CREATE TABLE uczniowie(
id_ucznia VARCHAR(100),
imie VARCHAR(100),
nazwisko VARCHAR(100),
klasa VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../matura/uczniowie.txt'
INTO TABLE uczniowie FIELDS TERMINATED BY ';' IGNORE 1 LINES;

DROP TABLE IF EXISTS przedmioty;

CREATE TABLE przedmioty(
id_przedmiotu INT,
nazwa_przedmiotu VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../matura/przedmioty.txt'
INTO TABLE przedmioty FIELDS TERMINATED BY ';' IGNORE 1 LINES;

DROP TABLE IF EXISTS oceny;

CREATE TABLE oceny(
id_ucznia VARCHAR(100),
id_oceny INT,
data VARCHAR(100),
id_przedmiotu INT
);

LOAD DATA LOCAL INFILE '../../../matura/oceny.txt'
INTO TABLE oceny FIELDS TERMINATED BY ';' IGNORE 1 LINES;

SELECT * FROM oceny LIMIT 1\G

