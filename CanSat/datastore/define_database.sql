DROP TABLE IF EXISTS data;
CREATE TABLE data
(
	time DATATIME,
	temperature INT,
	preasure INT,
	spectrum BLOB
);

INSERT INTO data VALUES ( "1998-05-02 19:34:32.000", 12, 12, X'65656565' );
INSERT INTO data VALUES ( "1992-05-23 23:23:34.000", 12, 12, X'65656565' );
INSERT INTO data VALUES ( "1998-05-02 19:34:30.000", 12, 12, X'65656565' );
INSERT INTO data VALUES ( "2001-05-02 19:34:34.090", 12, 12, X'6565646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465646564656465' );

SELECT * FROM data
ORDER BY time;