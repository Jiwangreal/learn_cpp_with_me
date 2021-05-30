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
第一步，按照时间分组取最大的 
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')

第二步，根据TRANS_ID找详细信息，把他看成一张表，它是一个子查询
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)

因为子查询和链接往往是可以互相转换的
第三步：对上面的这张表格进行连接，即子查询
select trans_id, balance, trans_date, "x" next_date,
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) a;


第四步：x是一个子查询(next_date),
子查询next_date要从select * from trans where trans_id in (
 select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')这里获取数据

select trans_id, balance, trans_date, (
select * from trans where trans_id in (
 select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)next_date,
from (
select * from trans where trans_id in (
select max(trans_id) from trans where account_id=1 group by date_format(trans_date, '%Y-%m-%d')
)
) a;

第五步，获取最小的trans_date
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

第六步，增加days字段
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


将"x" days写成：datediff(next_date, trans_date) days
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

优化
datediff(if(next_date, next_date, now()), trans_date) days表示next_date为空，则为当前时间now()，否则就是next_date
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

第六步，仅计算利息
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