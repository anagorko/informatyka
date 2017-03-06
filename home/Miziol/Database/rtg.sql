USE rtg;

DROP TABLE IF EXISTS pacjenci;
CREATE TABLE pacjenci
(
	pesel VARCHAR(11),
	nazwisko VARCHAR(100),
	imie VARCHAR(100),
	plec VARCHAR(1),
	NFZ VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/103/pacjenci.txt' INTO TABLE pacjenci FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS badania;
CREATE TABLE badania
(
	pesel VARCHAR(11),
	id_badania VARCHAR(7)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/103/badania.txt' INTO TABLE badania FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS rtg;
CREATE TABLE rtg
(
	id_badania VARCHAR(7),
	nazwa VARCHAR(100),
	cena INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/103/rtg.txt' INTO TABLE rtg FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;




#103.1
SELECT imie, nazwisko, LEFT( pacjenci.pesel, 2 ) as rok
FROM pacjenci, ( SELECT pesel, COUNT( * ) as ile
	FROM badania
	GROUP BY pesel) as wizyty
WHERE pacjenci.pesel = wizyty.pesel
GROUP BY pacjenci.pesel
ORDER BY ile DESC
LIMIT 1;


#103.2
SELECT NFZ, SUM( cena ) as koszt
FROM pacjenci, ( SELECT pesel, cena
	FROM badania, rtg
	WHERE badania.id_badania = rtg.id_badania ) as koszty
WHERE koszty.pesel = pacjenci.pesel
GROUP BY NFZ
ORDER BY koszt DESC;


#103.3 a)
SELECT nazwa, COUNT( * ) as ile_razy
FROM badania, rtg
WHERE badania.id_badania = rtg.id_badania
GROUP BY badania.id_badania
ORDER BY ile_razy DESC
LIMIT 1;


#103.3 b)
SELECT nazwa, COUNT( DISTINCT pesel ) as ile_razy
FROM badania, rtg
WHERE badania.id_badania = rtg.id_badania
GROUP BY badania.id_badania
ORDER BY ile_razy DESC
LIMIT 1;


#103.4
SELECT plec, COUNT( * )
FROM pacjenci, badania
WHERE badania.pesel = pacjenci.pesel
GROUP BY plec;


#103.5
SELECT LEFT( pesel, 1 ) +1 as dekada, COUNT( * ) as ile
FROM pacjenci
GROUP BY dekada;