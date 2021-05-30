create table TRANS
{
    TRANS_ID int not null auto_increment,
    ACCOUNT_ID int, int,
    OTHER_ACCOUNT_ID int,
    MONEY decimal(10,2),
    BALANCE decimal(10,2),
    TRANS_DATE datetime,
    primary key (TRANS_ID)
};

INSERT INTO TRANS VALUES (null,1,NULL,1,10000.00,10000.00,'204-03-01 12:16:35');
INSERT INTO TRANS VALUES (null,1,NULL,2,1000.00,11000.00,'204-03-01 12:16:35');
INSERT INTO TRANS VALUES (null,1,NULL,3,3000.00,8000.00,'204-03-01 12:16:35');
INSERT INTO TRANS VALUES (null,1,NULL,1,200000.00,208000.00,'204-03-04 12:16:35');
INSERT INTO TRANS VALUES (null,1,NULL,1,100000.00,108000.00,'204-03-06 12:16:35');

/*
��һ��������ʱ�����ȡ���� 
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')

�ڶ���������TRANS_ID����ϸ��Ϣ����������һ�ű�����һ���Ӳ�ѯ
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)

��Ϊ�Ӳ�ѯ�����������ǿ��Ի���ת����
������������������ű��������ӣ����Ӳ�ѯ
select trans_id, balance, trans_date, "x" next_date,
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) a;


���Ĳ���x��һ���Ӳ�ѯ(next_date),
�Ӳ�ѯnext_dateҪ��select * from trans where trans_id in (
 select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')�����ȡ����

select trans_id, balance, trans_date, (
select * from trans where trans_id in (
 select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)next_date,
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) a;

���岽����ȡ��С��trans_date
select trans_id, balance, trans_date, (
select min(trans_date) from (
select * from trans where trans_id in (
 select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
)b where b.trans_date > a.trans_date
)next_date,
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) a;

������������days�ֶ�
select trans_id, balance, trans_date, next_date, "x" days
from (
select trans_id, balance, trans_date, (
select min(trans_date) from (
select * from trans where trans_id in (
 select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
)b where b.trans_date > a.trans_date
)next_date,
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) a;
) xx


��"x" daysд�ɣ�datediff(next_date, trans_date) days
select trans_id, balance, trans_date, next_date, datediff(next_date, trans_date) days
from (
select trans_id, balance, trans_date, (
select min(trans_date) from (
select * from trans where trans_id in (
 select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
)b where b.trans_date > a.trans_date
)next_date,
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) a;
) xx

�Ż�
datediff(if(next_date, next_date, now()), trans_date) days��ʾnext_dateΪ�գ���Ϊ��ǰʱ��now()���������next_date
select trans_id, balance, trans_date, next_date, 
datediff(if(next_date, next_date, now()), trans_date) days
from (
select trans_id, balance, trans_date, (
select min(trans_date) from (
select * from trans where trans_id in (
 select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
)b where b.trans_date > a.trans_date
)next_date,
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) a;
) xx

����������������Ϣ
select sum(yy.days*yy.balance)*0.0035/360 interest
from
(
select trans_id, balance, trans_date, next_date,
datediff(if(next_date, next_date, now()), trans_date) days
from (
select trans_id, balance, trans_date, (
select min(trans_date) from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) b where b.trans_date > a.trans_date
) next_date
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
) 
) a
) xx
) yy

*/

select sum(yy.days*yy.balance)*0.0035/360 interest
from
(
select trans_id, balance, trans_date, next_date,
datediff(if(next_date, next_date, now()), trans_date) days
from (
select trans_id, balance, trans_date, (
select min(trans_date) from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) b where b.trans_date > a.trans_date
) next_date
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
) 
) a
) xx
) yy