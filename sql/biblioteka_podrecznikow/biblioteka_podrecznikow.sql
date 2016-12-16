USE biblioteka_podrecznikow;

DROP TABLE IF EXISTS studenci;
CREATE TABLE studenci (
  pesel BIGINT,
  nazwisko VARCHAR(100),
  imie VARCHAR(100)
);

LOAD DATA LOCAL INFILE 'studenci.txt' INTO TABLE studenci IGNORE 1 LINES;

DROP TABLE IF EXISTS meldunek;
CREATE TABLE meldunek (
  pesel BIGINT,
  id_pok INT
);

LOAD DATA LOCAL INFILE 'meldunek.txt' INTO TABLE meldunek IGNORE 1 LINES;

DROP TABLE IF EXISTS wypozyczenia;
CREATE TABLE wypozyczenia (
  lp INT,
  pesel BIGINT,
  tytul VARCHAR(100)
);

LOAD DATA LOCAL INFILE 'wypozyczenia.txt' INTO TABLE wypozyczenia IGNORE 1 LINES;

select imie, nazwisko, studenci.pesel, count(tytul) as ile from studenci, wypozyczenia where studenci.pesel = wypozyczenia.pesel group by studenci.pesel order by ile \G

select avg(x.liczba_osob) from (select id_pok, count(*) as liczba_osob from meldunek group by id_pok) x;
