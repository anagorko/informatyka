USE leki_refundowane;

DROP TABLE IF EXISTS recepty;
CREATE TABLE recepty
(
	id_recepty VARCHAR(9),
	data DATE,
	kod_leku VARCHAR(13)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/104/recepty.txt' INTO TABLE recepty FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS leki;
CREATE TABLE leki
(
	kod_leku VARCHAR(13),
	substancja VARCHAR(250),
	nazwa VARCHAR(250),
	id_grupy VARCHAR(5),
	cena_detaliczna DECIMAL(10,2),
	cena_refundowana DECIMAL(10,2)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/104/leki_refundowane.txt' INTO TABLE leki FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;

DROP TABLE IF EXISTS grupy_lekow;
CREATE TABLE grupy_lekow
(
	id_grupy VARCHAR(5),
	nazwa VARCHAR(250)
);

LOAD DATA LOCAL INFILE '../../../zbior_zadan/104/grupy_lekow.txt' INTO TABLE grupy_lekow FIELDS TERMINATED BY ';' LINES TERMINATED BY '\r\n' IGNORE 1 LINES;




SELECT data, COUNT( id_recepty ) as ile
FROM recepty
GROUP BY data
ORDER BY ile DESC
LIMIT 1;

SELECT nazwa
FROM grupy_lekow, ( SELECT id_grupy, COUNT( * ) as ile
	FROM leki
	WHERE cena_refundowana = 0.00
	GROUP BY id_grupy
	ORDER BY ile DESC, id_grupy
	LIMIT 1 ) as po_ile
WHERE po_ile.id_grupy = grupy_lekow.id_grupy;

SELECT MONTH( data ) as miesiac, SUM( cena_detaliczna )
FROM recepty, leki
WHERE recepty.kod_leku = leki.kod_leku
GROUP BY miesiac;

SELECT cena_detaliczna, grupy_lekow.nazwa
FROM recepty, leki, grupy_lekow
WHERE recepty.kod_leku = leki.kod_leku
	AND leki.id_grupy = grupy_lekow.id_grupy
GROUP BY recepty.kod_leku
ORDER BY cena_detaliczna DESC
LIMIT 1;

SELECT data, id_recepty, SUM( doplata ) as suma_doplat
FROM recepty, ( SELECT kod_leku, (cena_detaliczna - cena_refundowana) as doplata
	FROM leki ) as refundacja
WHERE refundacja.kod_leku = recepty.kod_leku
GROUP BY id_recepty
ORDER BY suma_doplat DESC
LIMIT 1;