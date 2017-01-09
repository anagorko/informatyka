USE e_learning;

DROP TABLE IF EXISTS osoby;

CREATE TABLE osoby(
id_osoby INT,
imie VARCHAR(100),
nazwisko VARCHAR(100),
grupa VARCHAR(100)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/100/osoby.txt'
INTO TABLE osoby IGNORE 1 LINES;

DROP TABLE IF EXISTS listy;

CREATE TABLE listy(
id_listy INT,
nazwa VARCHAR(100),
termin_oddania DATE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/100/listy.txt'
INTO TABLE listy IGNORE 1 LINES;

DROP TABLE IF EXISTS punktacja;

CREATE TABLE punktacja(
lp INT,
id_osoby INT,
id_listy INT,
punkty INT,
data DATE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/100/punktacja.txt'
INTO TABLE punktacja IGNORE 1 LINES;


#100.1
/*
SELECT listy.nazwa, ROUND(AVG(punkty),2)
FROM listy
	JOIN punktacja ON listy.id_listy = punktacja.id_listy
GROUP BY listy.nazwa;
*/
#100.2
/*
SELECT imie, nazwisko
FROM listy
	JOIN punktacja ON listy.id_listy = punktacja.id_listy
	JOIN osoby ON osoby.id_osoby = punktacja.id_osoby
WHERE nazwa LIKE 'P%'
	AND TO_DAYS(data)-TO_DAYS(termin_oddania) > 14;
*/
#100.3
/*
SELECT x.ocena, COUNT(ocena)
FROM
	(SELECT CASE WHEN punkty<71 then 1 ELSE 0 END AS ocena
	FROM punktacja)x
GROUP BY x.ocena;
*/
#100.4
/*
SELECT punkty, COUNT(punkty) AS ilosc
FROM punktacja
WHERE punkty = 10 OR punkty = 11 OR punkty = 12
GROUP BY punkty
*/
#100.5

SELECT imie, nazwisko
FROM osoby
WHERE id_osoby NOT IN
	(SELECT punktacja.id_osoby
	FROM osoby, punktacja, listy 
	WHERE punktacja.id_osoby = osoby.id_osoby
		AND listy.id_listy = punktacja.id_listy);

