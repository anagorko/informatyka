USE portal

DROP TABLE IF EXISTS uzytkownicy;
CREATE TABLE uzytkownicy
(
	id_uzytkownika INT,
	imie VARCHAR(100),
	nazwisko VARCHAR(100),
	kraj VARCHAR(100),
	plec VARCHAR(1)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/102/uzytkownicy.txt' INTO TABLE uzytkownicy LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS znajomosci;
CREATE TABLE znajomosci
(
	znajomy1 INT,
	znajomy2 INT,
	data DATE
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/102/znajomosci.txt' INTO TABLE znajomosci LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS zdjecia;
CREATE TABLE zdjecia
(
	id_zdjecia INT,
	data_dodania DATE,
	id_uzytkownika INT,
	szerokosc INT,
	wysokosc INT
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/102/zdjecia.txt' INTO TABLE zdjecia LINES TERMINATED BY '\r\n' IGNORE 1 LINES;



SELECT COUNT( * )
FROM zdjecia
WHERE YEAR( data_dodania ) = 2014;


SELECT imie1, nazwisko1, kraj1, imie2, nazwisko2, kraj2
FROM znajomosci,
	( SELECT id_uzytkownika as id1, imie as imie1, nazwisko as nazwisko1, kraj as kraj1
	FROM uzytkownicy ) as user1,
	( SELECT id_uzytkownika as id2, imie as imie2, nazwisko as nazwisko2, kraj as kraj2
	FROM uzytkownicy ) as user2
WHERE znajomosci.znajomy1 = user1.id1
	AND znajomosci.znajomy2 = user2.id2
	AND imie1 = imie2;

SELECT kraj, COUNT( * ) as ile
FROM zdjecia, uzytkownicy
WHERE zdjecia.id_uzytkownika = uzytkownicy.id_uzytkownika
GROUP BY kraj
ORDER BY ile DESC
LIMIT 10;

SELECT imie, nazwisko, szerokosc, wysokosc
FROM ( SELECT imie, nazwisko, szerokosc, wysokosc, (szerokosc * wysokosc) as rozmiar
	FROM zdjecia, uzytkownicy
	WHERE zdjecia.id_uzytkownika = uzytkownicy.id_uzytkownika ) as wielkosci
ORDER BY rozmiar DESC
LIMIT 1;


SELECT imie, nazwisko, kraj
FROM uzytkownicy,
	( SELECT *
	FROM zdjecia, znajomosci
	WHERE zdjecia.id_uzytkownika = znajomosci.znajomy1
		AND data < data_dodania
	GROUP BY zdjecia.id_uzytkownika
	ORDER BY id_uzytkownika ) as 1set,
	( SELECT *
	FROM zdjecia, znajomosci
	WHERE zdjecia.id_uzytkownika = znajomosci.znajomy2
		AND data < data_dodania
	GROUP BY zdjecia.id_uzytkownika
	ORDER BY id_uzytkownika ) as 2set
WHERE uzytkownicy.id_uzytkownika = 1set.id_uzytkownika
	OR uzytkownicy.id_uzytkownika = 2set.id_uzytkownika
GROUP BY uzytkownicy.id_uzytkownika
ORDER BY nazwisko