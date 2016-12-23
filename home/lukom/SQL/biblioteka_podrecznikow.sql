USE biblioteka_podrecznikow;

DROP TABLE IF EXISTS studenci;

CREATE TABLE studenci(
pesel BIGINT,
nazwisko VARCHAR(100),
imie VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../matura/studenci.txt'
INTO TABLE studenci IGNORE 1 LINES;

DROP TABLE IF EXISTS meldunek;

CREATE TABLE meldunek(
pesel BIGINT,
id_pok VARCHAR(100)
);
LOAD DATA LOCAL INFILE '../../../matura/meldunek.txt'
INTO TABLE meldunek IGNORE 1 LINES;

DROP TABLE IF EXISTS wypozyczenia;
CREATE TABLE wypozyczenia(
lp INT,
pesel BIGINT,
tytul VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../matura/wypozyczenia.txt'
INTO TABLE wypozyczenia IGNORE 1 LINES;

#5.1

SELECT imie, nazwisko, COUNT(tytul) AS ile 
FROM wypozyczenia,studenci 
WHERE wypozyczenia.pesel = studenci.pesel
GROUP BY wypozyczenia.pesel
ORDER BY ile DESC
LIMIT 1 \G

#odczytałem, że Lewandowski i sprawdzam liczbę książek:

SELECT tytul
FROM wypozyczenia, studenci
WHERE wypozyczenia.pesel = studenci.pesel
	AND studenci.nazwisko = 'LEWANDOWSKI'\G


#5.2
SELECT avg(x.liczba_osob)
FROM
	(SELECT COUNT(pesel) AS liczba_osob
	FROM meldunek
	GROUP BY id_pok)x \G

#5.3

SELECT count(*) AS ile_kobiet
FROM meldunek
WHERE SUBSTRING(pesel,10,1)%2=0 \G 

SELECT count(*) AS ile_mezczyzn
FROM meldunek
WHERE SUBSTRING(pesel, 10,1)%2<>0 \G

#5.4
SELECT imie, nazwisko 
FROM studenci
WHERE pesel NOT IN 
	(SELECT meldunek.pesel
	FROM meldunek, wypozyczenia
	WHERE meldunek.pesel = wypozyczenia.pesel)
ORDER BY nazwisko \G

#5.5
SELECT sum(x.nadwyzka)
FROM
	(SELECT id_pok, (count(tytul)-count(distinct tytul)) AS nadwyzka
	FROM wypozyczenia, meldunek
	WHERE wypozyczenia.pesel = meldunek.pesel
	GROUP BY id_pok)x \G
