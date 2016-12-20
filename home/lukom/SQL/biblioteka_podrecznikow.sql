USE biblioteka_podrecznikow;

DROP TABLE IF EXISTS studenci;

CREATE TABLE studenci(
pesel BIGINT,
nazwisko VARCHAR(100),
imie VARCHAR(100)
);

LOAD DATA LOCAL INFILE '/home/ki/Informatyka/matura/studenci.txt'
INTO TABLE studenci IGNORE 1 LINES;

DROP TABLE IF EXISTS meldunek;

CREATE TABLE meldunek(
pesel BIGINT,
id_pok VARCHAR(100)
);
LOAD DATA LOCAL INFILE '/home/ki/Informatyka/matura/meldunek.txt'
INTO TABLE meldunek IGNORE 1 LINES;

SELECT * FROM meldunek LIMIT 10;
