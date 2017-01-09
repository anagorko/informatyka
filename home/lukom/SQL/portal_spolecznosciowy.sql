USE portal_spolecznosciowy;

DROP TABLE IF EXISTS uzytkownicy;

CREATE TABLE uzytkownicy(
id_uzytkownika INT,
imie VARCHAR(100),
nazwisko VARCHAR(100),
kraj VARCHAR(100),
plec VARCHAR(1)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/102/uzytkownicy.txt'
INTO TABLE uzytkownicy IGNORE 1 LINES;

DROP TABLE IF EXISTS zanajomosci;

CREATE TABLE znajomosci( 
znajomy1 INT,
znajomy2 INT,
data DATE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/102/znajomosci.txt'
INTO TABLE znajomosci IGNORE 1 LINES;

DROP TABLE IF EXISTS zdjecia;

CREATE TABLE zdjecia( 
id_zdiecia INT,
data_dodania DATE,
id_uzytkownika INT,
szerokosc INT,
wysokosc INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/102/zdjecia.txt'
INTO TABLE zdjecia IGNORE 1 LINES;

#102.1
/*
SELECT COUNT(*) AS ilosc_zdjec
FROM zdjecia
WHERE YEAR(data_dodania) = 2014; 
*/
#102.2
/*
SELECT j.imie, j.nazwisko, j.kraj, d.imie, d.nazwisko, d.kraj
FROM znajomosci,
	(SELECT id_uzytkownika, imie, nazwisko, kraj
	FROM uzytkownicy)j
	,
	(SELECT id_uzytkownika, imie, nazwisko, kraj
	FROM uzytkownicy)d
WHERE znajomy1 = j.id_uzytkownika
	AND znajomy2 = d.id_uzytkownika
	AND j.imie = d.imie
GROUP BY znajomy1;
*/
#102.3
/*
SELECT kraj, COUNT(*) AS ilosc_zdjec
FROM zdjecia
	JOIN uzytkownicy ON uzytkownicy.id_uzytkownika = zdjecia.id_uzytkownika
GROUP BY kraj
ORDER BY ilosc_zdjec DESC;
*/
#102.4
/*
SELECT wysokosc, szerokosc, imie, nazwisko
FROM zdjecia
	JOIN uzytkownicy ON uzytkownicy.id_uzytkownika = zdjecia.id_uzytkownika
ORDER BY wysokosc*szerokosc DESC LIMIT 1; 
*/
#102.5
/*
SELECT imie, nazwisko, kraj
FROM uzytkownicy,
	(SELECT zdjecia.id_uzytkownika AS id_u
	FROM zdjecia, znajomosci, uzytkownicy
	WHERE (zdjecia.id_uzytkownika = znajomosci.znajomy1
		AND uzytkownicy.id_uzytkownika = znajomosci.znajomy1)
		OR
		(zdjecia.id_uzytkownika = znajomosci. znajomy2
		AND uzytkownicy.id_uzytkownika = znajomosci.znajomy2)
		AND plec = 'M'
		AND data_dodania < data)x
WHERE id_uzytkownika = x.id_u
GROUP BY id_uzytkownika
ORDER BY nazwisko;
*/
