第二十三讲
/*DDL语言*/
create table t_emp(empno int, ename varchar(20), esex char(2));
alter table t_emp modify ename varchar(30);
alter table t_emp drop esex;
alter table t_emp add esex char(2);

/* 
DML语言:给表增加一些记录 */
insert into t_emp(empno, ename, esex) values(1000, 'tom', 'm');
insert into t_emp values(1000, 'maggie', 'f');
insert into t_emp(empno, ename) values(1002, 'john');
insert into t_emp(empno, ename, esex) values(1003, null, 'm');
insert into t_emp values(1004, '张三', '男');

show variables like 'character_set%';

set names gbk;

update t_emp set empno=1001 where ename='maggie';
delete from t_emp where esex is null;

/* 删除表的所有记录 */
delete from t_emp;

/* 删除t_emp整张表 */
drop t_emp;


/* 注意：整数不用引号，字符串需要 */

第二十四讲

====主键约束====
create table t_emp(empno int not null primary key, ename varchar(20), esex char(2));普通字段也可以设置为not null
/* 等价于 */
create table t_emp(empno int primary key, ename varchar(20), esex char(2));
/* 等价于 */
create table t_emp(empno int, ename varchar(20), esex char(2), primary key (empno));
/* 等价于 */
PK_EMPNO大小写都行，给primary key加上约束
create table t_emp(empno int, ename varchar(20), esex char(2), constraint PK_EMPNO primary key(empno));
/* 等价于 */
create table t_emp(empno int, ename varchar(20), esex char(2));
alter table t_emp add constraint PK_EMPNO primary key(empno);

/* 2个字段联合作为一个主键 */
alter table t_emp add constraint PK_EMPNO primary key(XX1,XX2);

show create table t_emp;
/* 查看它的查询语句 */


insert into t_emp values(1000, 'john', 'm');
insert into t_emp values(1000, 'lily', 'f');
insert into t_emp values(null, 'lily', 'f');



====外键约束====

/* deptno是外键：参照完整性，员工表t_emp的部门号deptno要么是空的，要么是部门表t_dept中存在的记录 */
/* t_dept是父表， t_emp是子表，因为t_emp子表的deptno来自t_dept*/
create table t_emp(empno int, deptno int, ename varchar(20), esex char(2));
alter table t_emp add constraint PK_EMPNO primary key(empno);

create table t_dept(deptno int, dname varchar(20));
alter table t_dept add constraint PK_DEPTNO primary key(deptno);

/* deptno外键引用到了部门表t_dept中的deptno */
alter table t_emp add constraint FK_DEPTNO foreign key(deptno) references t_dept(deptno);

set names gbk;
insert into t_dept values(2001, '人事部');
insert into t_dept values(2002, '技术部');

/* 查看插入的记录 */
select * from t_emp;

insert into t_emp values(1001, 2001, 'john', 'm');
insert into t_emp values(1003, 2003, 'john', 'm');

/* 显示表结构 */
describe table t_dept;
/* 等价于 */
desc table t_dept;

显示所有数据库：show databases;
选定数据库：use dbname;
显示当前数据库中所有表：show tables;
要先选定数据库
显式指定数据库中的所有表：show tables from dbname;


/* 自动增长的字段 */
/* 自动增长的属性必定是主键 */
/*auto_increment是mysql自己的语法，oracle没有的*/
create table t_test1(id int auto_increment primary key, name varchar(30), age int default 20);
show create table t_test1;/* 查看它的查询语句 */
desc table t_test1;/*查看表结构*/

/* 用户自定义的约束 */
/* 主键不设置会自动增长 */
insert into t_test1 values(null, 'aaa');/*这样的写法是错误的*/
insert into t_test1 values(null, 'aaa', null);/*这样写，age=null*/
insert into t_test1 (name) values( 'bbb');/*这样写，age = 20*/
/* 查看插入的记录 */
select * from t_emp;

/* 用户自定义完整性约束	(check) mysql不支持，oracle支持*/
create table t_test2(id int, name varchar(30), age int);
alter table t_test2 add constraint CC_AGE check (age >=18 and age<=60);
alter table t_test2 add constraint CC_AGE check (length(name)>2);

第二十五讲
/* a是有符号的，b是无符号的 */
create table t_number(a tinyint, b tinyint unsigned);
insert into t_number values(100, 200);
insert into t_number values(-129, 200);/*error超过范围*/
insert into t_number values(128, 200);/*error*/
insert into t_number values(127, 200);/*error*/
insert into t_number values(127, -1);/*error*/

/*zerofill表示前导，用0来填充*/
create table t_number2(a int(4) zerofill);/*一个数不足4位，前导用0来填充*/
insert into t_number2 values(123);
/* 查看插入的记录 */
select * from t_number2;
insert into t_number2 values(123456);/*超过4bit，还是可以显示出来*/

create table t_number3(a bool);/*bool是tinyint(1)的别名*/
desc t_number3;



create table t_number4(a float, b double);
insert into t_number4 values(12345678.12345, 12345678.12345);/*float的会出现精度丢失*/
/* 查看插入的记录 */
select * from t_number4;

insert into t_number4 values(12345678.12345, 123456789123456789.12345);
/* 查看插入的记录 */
select * from t_number4;

insert into t_number4 values(12345678.12345, 12345678912345.12345);

/* 总位数=5，小数点后面的位数=2 */
create table t_number5(a double(5,2));
/* 表示数的范围如下 */
-999.99 ~999.99
insert into t_number5 values(-999.99);
insert into t_number5 values(999.99);
insert into t_number5 values(999.999);/*超过的范围就插入不成了*/
insert into t_number5 values(999.994);/*可以插入，但是会四舍五入的插入*/
/* 查看插入的记录 */
select * from t_number5;


/* 主位数=30bit，小数=6bit */
create table t_number6(a decimal(30,6));
insert into t_number6 values(123456789123456789.12345);
select * from t_number6;

create table t_number7(a decimal(5,2));
/* 表示数的范围如下 */
-999.99 ~999.99


第二十六讲
/* datetime存储的是8个字节的整数 */
create table t_datetime(a datetime);

/*插入的确是字符串*/
insert into t_datetime values('2014-01-15 10:10:10');
insert into t_datetime values('9999-12-31 23:59:59');
select * from t_datetime;

insert into t_datetime values('10000-01-01 00:00:00');/*error*/

/*当你需要同时包含日期和时间信息的值时则使用DATETIME类型。MySQL以'YYYY-MM-DD HH:MM:SS'格式检索和显示DATETIME值。
支持的范围为'1000-01-01 00:00:00'到'9999-12-31 23:59:59'。(“支持”表示尽管先前的值可能工作，但没有保证)。
from：MySQL 5.1参考手册.chm*/
insert into t_datetime values('999-01-01 00:00:00');/*可以插入成功*/
/*
自动补上的原因是：
o        00-69范围的年值转换为2000-2069。

o        70-99范围的年值转换为1970-1999。

from：MySQL 5.1参考手册.chm
*/
insert into t_datetime values('99-01-01 00:00:00');/*代表1999-01-01 00:00:00，mysql自动补上19*/
insert into t_datetime values('69-01-01 00:00:00');

/*timestamp内部是4个字节的整数*/
/*timestamp实际存储的是秒，距离1970-01-01 00:00:00它相差多少S，把这个整数存储到timestamp列中
所以它最多存到2038年*/
create table t_timestamp(a timestamp);
insert into t_timestamp values('2014-01-15 10:10:10');
insert into t_timestamp values('2038-01-19 03:14:07');/*最多插入的时间，按照美国时区计算的结果*/
insert into t_timestamp values('2038-01-19 03:14:08');/*因为这是中国时区时间，还可以插入*/
insert into t_timestamp values('2038-01-19 11:14:07');/*按照中国时区时间应该+8h，所以这才是中国最多表示的时间*/
insert into t_timestamp values('2038-01-19 11:14:08');/*error*/

create table t_date(a date);
insert into t_date values('2012-01-01');
select * from t_date;

/* time不仅可以表示时间，还可以表示2个时间的时间差，时间差还可以是负数 */
create table t_time(a time);
insert into t_time values('23:12:12');
insert into t_time values('823:12:12');
insert into t_time values('3 23:12:12');/*3表示3天，就是95:12:12*/
select * from t_time;

create table t_year(a year);
insert into t_year values (2000);/*可以直接用整数*/
select * from t_year;
insert into t_year values ('2155');/*用字符串的形式插入*/
insert into t_year values (2156);/*error，超过取值范围了*/

第二十七讲
/* varchar(M)这里的M表示字符数
因为当前的字符集是utf-8，一个字符占用3个字节，65535/3=21845个字符，这里最长的字符是21845个字符
 */
create table t_varchar(a varchar(65535));		// error，不能创建成功
create table t_varchar(a varchar(21845));		// error，不能创建成功，因为字符串长度，额外的2个字节没地方保存了
create table t_varchar(a varchar(21844));       /*相比上头的，减去1个字符，就是多出3个字节，所以是对的*/

/*枚举类型*/
create table t_enum(sex enum('male', 'female'));/*枚举的意思是只能插入male或者female*/
insert into t_enum values('male');
insert into t_enum values('female');
select * from t_enum;
insert into t_enum values('other');/*不能再插入其他值了*/

/* 枚举看过去像是字符串，实际上保存的是整数
这里的male实际上是1，
female实际上是2
*/
insert into t_enum values(1);
/* 甚至可以对字段sex进行加法运算 */
select sex+0 from t_enum;


create table t_set(favourite set('dog', 'cat', 'bird'));
insert into t_set values('dog,cat');/*喜欢2个宠物，注意dog,cat没有空格*/
insert into t_set values('dog,bird');
select * from t_set;
/* 实际上是按位存储
dog是1--------》1
cat是10-------》2
bird是110-----》4
 */
select favourite+0 from t_set;


第二十八讲
/* 查询指定列 */
select empno,ename,job from emp;
/* 查询所有列 */
select * from emp;

/* 列--别名 */
SELECT empno as '工号',ename '姓名' FROM emp;

/* 使用常量列 */
SELECT empno, 'C++教程网' FROM emp;

/* 连接符 */
SELECT empno,concat(ename,'#') FROM emp;

/* 查询部分行 */
/* 查询ename = 'SMITH'	的员工的empno, ename, job */
SELECT empno, ename, job FROM emp WHERE ename = 'SMITH'

/* 这里的<>也可以用!= */
SELECT empno, ename, job FROM emp WHERE ename <> 'SMITH'

SELECT empno, ename, sal FROM emp WHERE sal>= 1500

/* 数据查询-条件(and,or) */
SELECT * FROM emp WHERE deptno=30 and sal>1500;
SELECT * FROM emp WHERE job='MANAGER' or job='SALESMAN'

/* 数据查询-between and */
SELECT * FROM emp where sal BETWEEN 800 and 1500;
/* 等价于 */

/* 不在[800，1500]之间 */
SELECT * FROM emp where sal not BETWEEN 800 and 1500;
SELECT * FROM emp where sal >= 800 and sal <= 1500;

/* 查询空值 */
SELECT empno, ename, sal, comm FROM emp WHERE comm is null
/* 查询非空值 */
SELECT empno, ename, sal, comm FROM emp WHERE comm is not null

/* 找出名称=SMITH或者KING的记录 */
SELECT * FROM emp where ename in ('SMITH', 'KING');

/* 模糊查询-like */
/* 通配符: ‘%’  （0个多个字符） */
/* 通配符: ‘_’   （单个字符） */
/* 查询S打头的员工信息 */
SELECT * FROM emp where ename like 'S%';
SELECT * FROM emp where ename like 'S_ITH';

/* 数据查询-排序 */
/* 按照员工的名称进行排序，而且是降序 */
SELECT * FROM emp ORDER BY ename desc;

/* 按照第2个字段降序。若2个或者2个以上，名称一样的字段，可以用下面类似2这样的序号进行区分 */
SELECT empno, ename, job FROM emp ORDER BY 2 desc;

/* 按多个列名排序 */
/* 先基于jbo升序，再按照sal降序 */
SELECT * FROM emp ORDER BY job asc, sal desc;

第二十九讲
/* 只显示前5条记录，limit相当于是top功能 */
select * from emp ORDER BY sal limit 5;

limit可用于分页查询
/* 第一个字段表示offset，第二个字段表示查询的行数
若将查询的结果进行分页的话，一页是5行记录 */
select * from emp ORDER BY sal limit 0,5;显示前5条记录，就是0-4行，这是第一页的内容
select * from emp ORDER BY sal limit 5,5;这是第二页的内容
select * from emp ORDER BY sal limit 10,5;若内容不足5行，比如只有4行，就显示4行

/* 去除重复记录 */
select distinct job,deptno from emp;
/* 默认带all，不去除关键字的 */
select job,deptno from emp;
等价于
select all job,deptno from emp;

/* 查询有员工的部门信息？ */
SELECT DISTINCT deptno from emp查询返回一个结果集，这就是一个集合，部门号在结果集里面，这是一个子查询
select * from dept where deptno in (SELECT DISTINCT deptno from emp);

查询有员工的部门信息
select * from dept where deptno in (SELECT DISTINCT deptno from emp);

union即联合查询
/*  
union即联合查询，将多个查询联合在一起
UNION (无重复并集)：当执行UNION 时，自动去掉结果集中的重复行，并以第一列的结果进行升序排序。
 */
select empno,ename,job from emp where job='SALESMAN'
union 
select empno,ename,job from emp where job='MANAGER';

select empno,ename,job from emp where job='SALESMAN' or job='MANAGER'

/* UNION ALL (有重复并集)：不去掉重复行，并且不对结果集进行排序。 */
select job, sal from emp where empno=7902
union all
select job, sal from emp where empno=7788;

select job, sal from emp where empno=7902
union
select job, sal from emp where empno=7788;

第三十讲
select * from emp,dept

/* A表：emp 
B表：dept 
从A表取出一条记录deptno，与B表进行比较，根据deptno相等进行连接的 */
SELECT * FROM emp INNER JOIN dept ON emp.deptno = dept.deptno;
/* INNER JOIN说明是内连接 */
select * from emp,dept where emp.deptno=dept.deptno;
/* 常用 */

/* emp员工表的deptno号大于的部门表dept的deptno号 */
select * from emp INNER JOIN dept on emp.deptno > dept.deptno;
/* 或按如下实现 */
select * from emp,dept where emp.deptno > dept.deptno;
/* 
查询员工以及对应的领导(自身连接)
连接条件和字段是不一样的
A和B都是自身，A表的mgr =B表的empno */
select A.ename 员工, B.ename 领导  from emp A, emp B where A.mgr = B.empno

/* 思路：
A表是emp，B表也是emp
A.ename A.mgr B.ename A.mgr=B.empno  */


SELECT * FROM emp INNER JOIN dept ON emp.deptno = dept.deptno;

/* 这里的主表是emp，dept是次表。emp表取出一条记录与dept表进行连接 */
select * from emp left [outer] join dept on emp.deptno=dept.deptno
/* 等价于，[outer] 可以省略 */
select * from emp left join dept on emp.deptno=dept.deptno

insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (9999, 'XXXX', 'CLERK', 7782, '1982-01-23', 1300, null, 90);

/* 现在以dept表为基准 */
select * from emp right [outer] join dept on emp.deptno=dept.deptno

select * from emp left join dept on emp.deptno=dept.deptno

SELECT *
FROM emp NATURAL JOIN dept;

SELECT *
FROM emp NATURAL LEFT JOIN dept;

SELECT *
FROM emp NATURAL RIGHT JOIN dept;

第三十一讲

select A.ename 员工, B.ename 领导  from emp A, emp B where A.mgr = B.empno;

/* select ename from emp where empno = e.mgr的e是外层的emp表。这里的emp表与外层的emp表是不一样的 */
select ename 员工, (select ename from emp where empno = e.mgr) 领导
from emp e;/*这里的e是这里的emp表的别名*/

select ename, dname from emp,dept where job='CLERK' and emp.deptno = dept.deptno;

select ename, (select dname from dept where deptno=e.deptno) dname
from emp e where job='CLERK';

/* on表示条件 */
select ename, dname from emp  LEFT JOIN dept on emp.deptno = dept.deptno where job='CLERK';

/* in表示在这个集合里面，in表示是否在这个集合中，不在这个集合就用no in*/
/* 子查询出现在where子句中 */
select ename, (select dname from dept where deptno=e.deptno) dname
from emp e where job='CLERK' and deptno in (select deptno from dept);

/* 子查询只有1条记录，且该记录中只有1个字段，可以这么用 ，若有多个字段则不能这么用*/
select * from emp where sal > (select sal from emp where ename='SMITH');
select * from emp e where hiredate < (select hiredate from emp where empno=e.mgr);

/* (select ename, (select dname from dept where deptno=e.deptno) dname
from emp e where job='CLERK')子查询的别名是a ，且该子查询语句是出现在from语句中*/
select ename, dname
from
(select ename, (select dname from dept where deptno=e.deptno) dname
from emp e where job='CLERK') a
where dname is not null;

/* 查询薪金小于销售员某个员工的员工信息 */
select * from emp WHERE
sal < any (select sal from emp where job='SALESMAN');
/* 结果等价于 */
/* select max(sal) from emp where job='SALESMAN'销售员中最大记录 */
/* max是聚合函数 */
select * from emp WHERE
sal < (select max(sal) from emp where job='SALESMAN');

/* 查询薪金大于所有销售员的员工信息 */
select * from emp WHERE
sal > all (select sal from emp where job='SALESMAN');

/* 列出与“SCOTT”从事相同工作的所有员工。 */
select * from emp e where EXISTS
(
select * from emp where ename='SCOTT' and e.job = job
);

/* select job from emp where ename='SCOTT'找到SCOTT的工作类型 */
select * from emp where job =(select job from emp where ename='SCOTT');



第三十二讲
/* 统计所有非空字段 */
select count(comm) as 记录数 from emp;

/* 统计所有行，即所有字段的数量，若一行都死null，也算是一条记录 */
select count(*) as 记录数 from emp;

/* 统计所有行，但是扫描的是行首，行首是空的，也算是一行 */
select count(0) as 记录数 from emp;

/* 统计所有行，但是扫描的是行首，行首是空的，不算是一行 */
select count(empno) as 记录数 from emp;

select avg(sal) as 平均薪金,
max(sal) as 最高薪金,
min(sal) as 最低薪金,
sum(sal) as 薪金总和
from emp;

/* 统计各个部门的员工数 */
/* 按照deptno进行分组 */
select deptno, count(*), from emp group by deptno;
/* 分组之后的条件用HAVING，不要用where */
select deptno, count(*) cn from emp group by deptno HAVING cn > 3;
/* 对cn进行降序 */
select deptno, count(*) cn from emp group by deptno HAVING cn > 3 ORDER BY cn desc;

/*列出各部门信息以及部门人数。  */
/* 对emp表进行分组才能求出部门人数 */
select *, (select count(*) from emp group by deptno HAVING deptno = dept.deptno) total 
from dept;

/* ifnull判断查询的字段是否为空，为空则给他一个0 */
select *, ifnull((select count(*) from emp group by deptno HAVING deptno = dept.deptno), 0) total 
from dept;

/* 查询出薪金成本最高的部门的部门号和部门名称 */
/* 用连接的方式： 将dept表和emp表连接在一起，但是只是取出了dept.deptno, dept.dname这俩字段*/
/* select dept.deptno, dept.dname
from dept首先找出部门号和部门名称

为什么sum(sal)取部门总工资，因为这里对它group by dept.deptno, dept.dname分组了，select的字段只能是分组group by的字段
select dept.deptno, dept.dname, sum(sal)
from dept, emp
where dept.deptno=emp.deptno
group by dept.deptno, dept.dname
 */
 /* select sum(sal) from emp group by deptno是每个部门的总薪资，是对部门进行分组，有多条记录的，子查询 */
select dept.deptno, dept.dname
from dept, emp
where dept.deptno=emp.deptno
group by dept.deptno, dept.dname
HAVING sum(sal) >= all (select sum(sal) from emp group by deptno)

/* 用子查询的方式 :select sum(sal) from emp group by deptno 看出是一个子查询
select dept.deptno, dept.dname
from dept, emp
where dept.deptno=emp.deptno
group by dept.deptno, dept.dname
HAVING sum(sal) >=(
select t.total
from
(select sum(sal) total from emp group by deptno) t
)

然后对它求最大值
select t.total
from
(select sum(sal) total from emp group by deptno) t

select max(t.total)
from
(select sum(sal) total from emp group by deptno) t

*/
select dept.deptno, dept.dname
from dept, emp
where dept.deptno=emp.deptno
group by dept.deptno, dept.dname
HAVING sum(sal) >= (
select max(t.total)
from
(select sum(sal) total from emp group by deptno) t
)


第三十三讲
CASE value WHEN [compare-value] THEN result [WHEN [compare-value] THEN result ...] [ELSE result] END

CASE WHEN [condition] THEN result [WHEN [condition] THEN result ...] [ELSE result] END 

/* from：MySql5.1参考手册中的12.2. 控制流程函数的eg */
/* when后面的1与CASE后面的1进行比较，若相等则输出one*/
/* CASE后面的1还可能是数据库中的某个字段 */
SELECT CASE 1 WHEN 1 THEN 'one' 
WHEN 2 THEN 'two' ELSE 'more' END;

/* CASE后面1>0则输出true */
SELECT CASE WHEN 1>0 THEN 'true' ELSE 'false' END;

/* emp表和salgrade表要连接在一起，使用连接查询 
连接条件是在最低工资和最高工资之间

select ename, sal, grade
from emp, salgrade
where sal between losal and hisal;

*/

select ename 员工, sal 薪金, case grade when 1 then '一级'
when 2 then '二级'
when 3 then '三级'
when 4 then '四级'
when 5 then '五级'
end 等级
from emp, salgrade
where sal between losal and hisal

/* ASCII(str) 
返回值为字符串str 的最左字符的数值。
 */
SELECT ASCII('2a');
SELECT ASCII('a2');
/* BIN(N) 
返回值为N的二进制值的字符串表示
 */
SELECT BIN(12);
/* BIT_LENGTH(str) 
返回值为二进制的字符串str 长度。
 */
/* 每个字符8位，返回的就是32位 */
SELECT BIT_LENGTH('text');

/* CHAR(N,... [USING charset]) 
CHAR()将每个参数N理解为一个整数，其返回值为一个包含这些整数的代码值所给出的字符的字符串。NULL值被省略。 
 */
SELECT CHAR(77,121,83,81,'76');
/* 结果是一样的 */
SELECT CHAR(77,121,83,81,76);

/* CHAR_LENGTH(str) 
返回值为字符串str 的长度，长度的单位为字符 */

/* CONCAT(str1,str2,...)                        
返回结果为连接参数产生的字符串。
 */
mysql> SELECT CONCAT('My', 'S', 'QL');
        -> 'MySQL'


SELECT 3+5;
SELECT 3/5;

SELECT ABS(-32);

select now();

SELECT DATE_ADD('1998-02-02', INTERVAL 31 DAY);

SELECT DATE_ADD('1998-02-02', INTERVAL 28 DAY);
/* 结果一样 */
SELECT adddate('1998-02-02', INTERVAL 28 DAY);
/* 结果一样 */
SELECT adddate('1998-02-02', 28);

/* DATEDIFF计算两个日期的时间差，以天为时间差*/
select DATEDIFF(now(),'2014-02-01');
select DATEDIFF('2014-02-01','2014-03-01');

/* DATE_FORMAT对时间格式化 */
/* '%H:%i:%s'表示只取出时分秒 */
select DATE_FORMAT(now(), '%H:%i:%s');

select DATE_FORMAT(now(), '%Y%M%D');

select DATE_FORMAT(now(), '%Y%m%d');