USE e_learning;

DROP TABLE IF EXISTS osoby;
CREATE TABLE osoby
(
	id_osoby INT,
	imie VARCHAR(100),
	nazwisko VARCHAR(100),
	grupa VARCHAR(2)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/100/osoby.txt' INTO TABLE osoby LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS listy;
CREATE TABLE listy
(
	id_listy INT,
	nazwa VARCHAR(2),
	termin_oddania DATE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/100/listy.txt' INTO TABLE listy LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS punktacja;
CREATE TABLE punktacja
(
	lp INT,
	id_osoby INT,
	id_listy INT,
	punkty INT,
	data DATE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/100/punktacja.txt' INTO TABLE punktacja LINES TERMINATED BY '\r\n' IGNORE 1 LINES;


SELECT nazwa, ROUND( AVG( punkty ), 2 )
FROM punktacja, listy
WHERE punktacja.id_listy = listy.id_listy
GROUP BY listy.id_listy;


SELECT imie, nazwisko
FROM osoby, punktacja, listy
WHERE punktacja.id_osoby = osoby.id_osoby
	AND punktacja.id_listy = listy.id_listy
	AND nazwa LIKE 'P%'
	AND termin_oddania + 14 <= data;

SELECT ocena, COUNT( * ) as ile
FROM ( SELECT CASE WHEN SUM( punkty ) < 72 THEN 1 
		WHEN SUM( punkty ) < 90 THEN 2
		WHEN SUM( punkty ) < 126 THEN 3
		WHEN SUM( punkty ) < 153 THEN 4
		WHEN SUM( punkty ) < 180 THEN 5 END ocena
		FROM punktacja
		GROUP BY id_osoby ) as oceny
GROUP BY ocena;


#100.4 nie rozumiem treści

SELECT imie, nazwisko
FROM osoby,
	(SELECT id_osoby, COUNT( id_listy ) as ile
		FROM punktacja
		GROUP BY id_osoby) as wyslane
WHERE wyslane.id_osoby = osoby.id_osoby AND wyslane.ile < 11
GROUP BY osoby.id_osoby;