�ڶ�ʮ����
/*DDL����*/
create table t_emp(empno int, ename varchar(20), esex char(2));
alter table t_emp modify ename varchar(30);
alter table t_emp drop esex;
alter table t_emp add esex char(2);

/* 
DML����:��������һЩ��¼ */
insert into t_emp(empno, ename, esex) values(1000, 'tom', 'm');
insert into t_emp values(1000, 'maggie', 'f');
insert into t_emp(empno, ename) values(1002, 'john');
insert into t_emp(empno, ename, esex) values(1003, null, 'm');
insert into t_emp values(1004, '����', '��');

show variables like 'character_set%';

set names gbk;

update t_emp set empno=1001 where ename='maggie';
delete from t_emp where esex is null;

/* ɾ��������м�¼ */
delete from t_emp;

/* ɾ��t_emp���ű� */
drop t_emp;


/* ע�⣺�����������ţ��ַ�����Ҫ */

�ڶ�ʮ�Ľ�

====����Լ��====
create table t_emp(empno int not null primary key, ename varchar(20), esex char(2));��ͨ�ֶ�Ҳ��������Ϊnot null
/* �ȼ��� */
create table t_emp(empno int primary key, ename varchar(20), esex char(2));
/* �ȼ��� */
create table t_emp(empno int, ename varchar(20), esex char(2), primary key (empno));
/* �ȼ��� */
PK_EMPNO��Сд���У���primary key����Լ��
create table t_emp(empno int, ename varchar(20), esex char(2), constraint PK_EMPNO primary key(empno));
/* �ȼ��� */
create table t_emp(empno int, ename varchar(20), esex char(2));
alter table t_emp add constraint PK_EMPNO primary key(empno);

/* 2���ֶ�������Ϊһ������ */
alter table t_emp add constraint PK_EMPNO primary key(XX1,XX2);

show create table t_emp;
/* �鿴���Ĳ�ѯ��� */


insert into t_emp values(1000, 'john', 'm');
insert into t_emp values(1000, 'lily', 'f');
insert into t_emp values(null, 'lily', 'f');



====���Լ��====

/* deptno����������������ԣ�Ա����t_emp�Ĳ��ź�deptnoҪô�ǿյģ�Ҫô�ǲ��ű�t_dept�д��ڵļ�¼ */
/* t_dept�Ǹ��� t_emp���ӱ���Ϊt_emp�ӱ��deptno����t_dept*/
create table t_emp(empno int, deptno int, ename varchar(20), esex char(2));
alter table t_emp add constraint PK_EMPNO primary key(empno);

create table t_dept(deptno int, dname varchar(20));
alter table t_dept add constraint PK_DEPTNO primary key(deptno);

/* deptno������õ��˲��ű�t_dept�е�deptno */
alter table t_emp add constraint FK_DEPTNO foreign key(deptno) references t_dept(deptno);

set names gbk;
insert into t_dept values(2001, '���²�');
insert into t_dept values(2002, '������');

/* �鿴����ļ�¼ */
select * from t_emp;

insert into t_emp values(1001, 2001, 'john', 'm');
insert into t_emp values(1003, 2003, 'john', 'm');

/* ��ʾ��ṹ */
describe table t_dept;
/* �ȼ��� */
desc table t_dept;

��ʾ�������ݿ⣺show databases;
ѡ�����ݿ⣺use dbname;
��ʾ��ǰ���ݿ������б�show tables;
Ҫ��ѡ�����ݿ�
��ʽָ�����ݿ��е����б�show tables from dbname;


/* �Զ��������ֶ� */
/* �Զ����������Աض������� */
/*auto_increment��mysql�Լ����﷨��oracleû�е�*/
create table t_test1(id int auto_increment primary key, name varchar(30), age int default 20);
show create table t_test1;/* �鿴���Ĳ�ѯ��� */
desc table t_test1;/*�鿴��ṹ*/

/* �û��Զ����Լ�� */
/* ���������û��Զ����� */
insert into t_test1 values(null, 'aaa');/*������д���Ǵ����*/
insert into t_test1 values(null, 'aaa', null);/*����д��age=null*/
insert into t_test1 (name) values( 'bbb');/*����д��age = 20*/
/* �鿴����ļ�¼ */
select * from t_emp;

/* �û��Զ���������Լ��	(check) mysql��֧�֣�oracle֧��*/
create table t_test2(id int, name varchar(30), age int);
alter table t_test2 add constraint CC_AGE check (age >=18 and age<=60);
alter table t_test2 add constraint CC_AGE check (length(name)>2);

�ڶ�ʮ�彲
/* a���з��ŵģ�b���޷��ŵ� */
create table t_number(a tinyint, b tinyint unsigned);
insert into t_number values(100, 200);
insert into t_number values(-129, 200);/*error������Χ*/
insert into t_number values(128, 200);/*error*/
insert into t_number values(127, 200);/*error*/
insert into t_number values(127, -1);/*error*/

/*zerofill��ʾǰ������0�����*/
create table t_number2(a int(4) zerofill);/*һ��������4λ��ǰ����0�����*/
insert into t_number2 values(123);
/* �鿴����ļ�¼ */
select * from t_number2;
insert into t_number2 values(123456);/*����4bit�����ǿ�����ʾ����*/

create table t_number3(a bool);/*bool��tinyint(1)�ı���*/
desc t_number3;



create table t_number4(a float, b double);
insert into t_number4 values(12345678.12345, 12345678.12345);/*float�Ļ���־��ȶ�ʧ*/
/* �鿴����ļ�¼ */
select * from t_number4;

insert into t_number4 values(12345678.12345, 123456789123456789.12345);
/* �鿴����ļ�¼ */
select * from t_number4;

insert into t_number4 values(12345678.12345, 12345678912345.12345);

/* ��λ��=5��С��������λ��=2 */
create table t_number5(a double(5,2));
/* ��ʾ���ķ�Χ���� */
-999.99 ~999.99
insert into t_number5 values(-999.99);
insert into t_number5 values(999.99);
insert into t_number5 values(999.999);/*�����ķ�Χ�Ͳ��벻����*/
insert into t_number5 values(999.994);/*���Բ��룬���ǻ���������Ĳ���*/
/* �鿴����ļ�¼ */
select * from t_number5;


/* ��λ��=30bit��С��=6bit */
create table t_number6(a decimal(30,6));
insert into t_number6 values(123456789123456789.12345);
select * from t_number6;

create table t_number7(a decimal(5,2));
/* ��ʾ���ķ�Χ���� */
-999.99 ~999.99


�ڶ�ʮ����
/* datetime�洢����8���ֽڵ����� */
create table t_datetime(a datetime);

/*�����ȷ���ַ���*/
insert into t_datetime values('2014-01-15 10:10:10');
insert into t_datetime values('9999-12-31 23:59:59');
select * from t_datetime;

insert into t_datetime values('10000-01-01 00:00:00');/*error*/

/*������Ҫͬʱ�������ں�ʱ����Ϣ��ֵʱ��ʹ��DATETIME���͡�MySQL��'YYYY-MM-DD HH:MM:SS'��ʽ��������ʾDATETIMEֵ��
֧�ֵķ�ΧΪ'1000-01-01 00:00:00'��'9999-12-31 23:59:59'��(��֧�֡���ʾ������ǰ��ֵ���ܹ�������û�б�֤)��
from��MySQL 5.1�ο��ֲ�.chm*/
insert into t_datetime values('999-01-01 00:00:00');/*���Բ���ɹ�*/
/*
�Զ����ϵ�ԭ���ǣ�
o        00-69��Χ����ֵת��Ϊ2000-2069��

o        70-99��Χ����ֵת��Ϊ1970-1999��

from��MySQL 5.1�ο��ֲ�.chm
*/
insert into t_datetime values('99-01-01 00:00:00');/*����1999-01-01 00:00:00��mysql�Զ�����19*/
insert into t_datetime values('69-01-01 00:00:00');

/*timestamp�ڲ���4���ֽڵ�����*/
/*timestampʵ�ʴ洢�����룬����1970-01-01 00:00:00��������S������������洢��timestamp����
���������浽2038��*/
create table t_timestamp(a timestamp);
insert into t_timestamp values('2014-01-15 10:10:10');
insert into t_timestamp values('2038-01-19 03:14:07');/*�������ʱ�䣬��������ʱ������Ľ��*/
insert into t_timestamp values('2038-01-19 03:14:08');/*��Ϊ�����й�ʱ��ʱ�䣬�����Բ���*/
insert into t_timestamp values('2038-01-19 11:14:07');/*�����й�ʱ��ʱ��Ӧ��+8h������������й�����ʾ��ʱ��*/
insert into t_timestamp values('2038-01-19 11:14:08');/*error*/

create table t_date(a date);
insert into t_date values('2012-01-01');
select * from t_date;

/* time�������Ա�ʾʱ�䣬�����Ա�ʾ2��ʱ���ʱ��ʱ�������Ǹ��� */
create table t_time(a time);
insert into t_time values('23:12:12');
insert into t_time values('823:12:12');
insert into t_time values('3 23:12:12');/*3��ʾ3�죬����95:12:12*/
select * from t_time;

create table t_year(a year);
insert into t_year values (2000);/*����ֱ��������*/
select * from t_year;
insert into t_year values ('2155');/*���ַ�������ʽ����*/
insert into t_year values (2156);/*error������ȡֵ��Χ��*/

�ڶ�ʮ�߽�
/* varchar(M)�����M��ʾ�ַ���
��Ϊ��ǰ���ַ�����utf-8��һ���ַ�ռ��3���ֽڣ�65535/3=21845���ַ�����������ַ���21845���ַ�
 */
create table t_varchar(a varchar(65535));		// error�����ܴ����ɹ�
create table t_varchar(a varchar(21845));		// error�����ܴ����ɹ�����Ϊ�ַ������ȣ������2���ֽ�û�ط�������
create table t_varchar(a varchar(21844));       /*�����ͷ�ģ���ȥ1���ַ������Ƕ��3���ֽڣ������ǶԵ�*/

/*ö������*/
create table t_enum(sex enum('male', 'female'));/*ö�ٵ���˼��ֻ�ܲ���male����female*/
insert into t_enum values('male');
insert into t_enum values('female');
select * from t_enum;
insert into t_enum values('other');/*�����ٲ�������ֵ��*/

/* ö�ٿ���ȥ�����ַ�����ʵ���ϱ����������
�����maleʵ������1��
femaleʵ������2
*/
insert into t_enum values(1);
/* �������Զ��ֶ�sex���мӷ����� */
select sex+0 from t_enum;


create table t_set(favourite set('dog', 'cat', 'bird'));
insert into t_set values('dog,cat');/*ϲ��2�����ע��dog,catû�пո�*/
insert into t_set values('dog,bird');
select * from t_set;
/* ʵ�����ǰ�λ�洢
dog��1--------��1
cat��10-------��2
bird��110-----��4
 */
select favourite+0 from t_set;


�ڶ�ʮ�˽�
/* ��ѯָ���� */
select empno,ename,job from emp;
/* ��ѯ������ */
select * from emp;

/* ��--���� */
SELECT empno as '����',ename '����' FROM emp;

/* ʹ�ó����� */
SELECT empno, 'C++�̳���' FROM emp;

/* ���ӷ� */
SELECT empno,concat(ename,'#') FROM emp;

/* ��ѯ������ */
/* ��ѯename = 'SMITH'	��Ա����empno, ename, job */
SELECT empno, ename, job FROM emp WHERE ename = 'SMITH'

/* �����<>Ҳ������!= */
SELECT empno, ename, job FROM emp WHERE ename <> 'SMITH'

SELECT empno, ename, sal FROM emp WHERE sal>= 1500

/* ���ݲ�ѯ-����(and,or) */
SELECT * FROM emp WHERE deptno=30 and sal>1500;
SELECT * FROM emp WHERE job='MANAGER' or job='SALESMAN'

/* ���ݲ�ѯ-between and */
SELECT * FROM emp where sal BETWEEN 800 and 1500;
/* �ȼ��� */

/* ����[800��1500]֮�� */
SELECT * FROM emp where sal not BETWEEN 800 and 1500;
SELECT * FROM emp where sal >= 800 and sal <= 1500;

/* ��ѯ��ֵ */
SELECT empno, ename, sal, comm FROM emp WHERE comm is null
/* ��ѯ�ǿ�ֵ */
SELECT empno, ename, sal, comm FROM emp WHERE comm is not null

/* �ҳ�����=SMITH����KING�ļ�¼ */
SELECT * FROM emp where ename in ('SMITH', 'KING');

/* ģ����ѯ-like */
/* ͨ���: ��%��  ��0������ַ��� */
/* ͨ���: ��_��   �������ַ��� */
/* ��ѯS��ͷ��Ա����Ϣ */
SELECT * FROM emp where ename like 'S%';
SELECT * FROM emp where ename like 'S_ITH';

/* ���ݲ�ѯ-���� */
/* ����Ա�������ƽ������򣬶����ǽ��� */
SELECT * FROM emp ORDER BY ename desc;

/* ���յ�2���ֶν�����2������2�����ϣ�����һ�����ֶΣ���������������2��������Ž������� */
SELECT empno, ename, job FROM emp ORDER BY 2 desc;

/* ������������� */
/* �Ȼ���jbo�����ٰ���sal���� */
SELECT * FROM emp ORDER BY job asc, sal desc;

�ڶ�ʮ�Ž�
/* ֻ��ʾǰ5����¼��limit�൱����top���� */
select * from emp ORDER BY sal limit 5;

limit�����ڷ�ҳ��ѯ
/* ��һ���ֶα�ʾoffset���ڶ����ֶα�ʾ��ѯ������
������ѯ�Ľ�����з�ҳ�Ļ���һҳ��5�м�¼ */
select * from emp ORDER BY sal limit 0,5;��ʾǰ5����¼������0-4�У����ǵ�һҳ������
select * from emp ORDER BY sal limit 5,5;���ǵڶ�ҳ������
select * from emp ORDER BY sal limit 10,5;�����ݲ���5�У�����ֻ��4�У�����ʾ4��

/* ȥ���ظ���¼ */
select distinct job,deptno from emp;
/* Ĭ�ϴ�all����ȥ���ؼ��ֵ� */
select job,deptno from emp;
�ȼ���
select all job,deptno from emp;

/* ��ѯ��Ա���Ĳ�����Ϣ�� */
SELECT DISTINCT deptno from emp��ѯ����һ��������������һ�����ϣ����ź��ڽ�������棬����һ���Ӳ�ѯ
select * from dept where deptno in (SELECT DISTINCT deptno from emp);

��ѯ��Ա���Ĳ�����Ϣ
select * from dept where deptno in (SELECT DISTINCT deptno from emp);

union�����ϲ�ѯ
/*  
union�����ϲ�ѯ���������ѯ������һ��
UNION (���ظ�����)����ִ��UNION ʱ���Զ�ȥ��������е��ظ��У����Ե�һ�еĽ��������������
 */
select empno,ename,job from emp where job='SALESMAN'
union 
select empno,ename,job from emp where job='MANAGER';

select empno,ename,job from emp where job='SALESMAN' or job='MANAGER'

/* UNION ALL (���ظ�����)����ȥ���ظ��У����Ҳ��Խ������������ */
select job, sal from emp where empno=7902
union all
select job, sal from emp where empno=7788;

select job, sal from emp where empno=7902
union
select job, sal from emp where empno=7788;

����ʮ��
select * from emp,dept

/* A��emp 
B��dept 
��A��ȡ��һ����¼deptno����B����бȽϣ�����deptno��Ƚ������ӵ� */
SELECT * FROM emp INNER JOIN dept ON emp.deptno = dept.deptno;
/* INNER JOIN˵���������� */
select * from emp,dept where emp.deptno=dept.deptno;
/* ���� */

/* empԱ�����deptno�Ŵ��ڵĲ��ű�dept��deptno�� */
select * from emp INNER JOIN dept on emp.deptno > dept.deptno;
/* ������ʵ�� */
select * from emp,dept where emp.deptno > dept.deptno;
/* 
��ѯԱ���Լ���Ӧ���쵼(��������)
�����������ֶ��ǲ�һ����
A��B��������A���mgr =B���empno */
select A.ename Ա��, B.ename �쵼  from emp A, emp B where A.mgr = B.empno

/* ˼·��
A����emp��B��Ҳ��emp
A.ename A.mgr B.ename A.mgr=B.empno  */


SELECT * FROM emp INNER JOIN dept ON emp.deptno = dept.deptno;

/* �����������emp��dept�Ǵα�emp��ȡ��һ����¼��dept��������� */
select * from emp left [outer] join dept on emp.deptno=dept.deptno
/* �ȼ��ڣ�[outer] ����ʡ�� */
select * from emp left join dept on emp.deptno=dept.deptno

insert into EMP (empno, ename, job, mgr, hiredate, sal, comm, deptno)
values (9999, 'XXXX', 'CLERK', 7782, '1982-01-23', 1300, null, 90);

/* ������dept��Ϊ��׼ */
select * from emp right [outer] join dept on emp.deptno=dept.deptno

select * from emp left join dept on emp.deptno=dept.deptno

SELECT *
FROM emp NATURAL JOIN dept;

SELECT *
FROM emp NATURAL LEFT JOIN dept;

SELECT *
FROM emp NATURAL RIGHT JOIN dept;

����ʮһ��

select A.ename Ա��, B.ename �쵼  from emp A, emp B where A.mgr = B.empno;

/* select ename from emp where empno = e.mgr��e������emp�������emp��������emp���ǲ�һ���� */
select ename Ա��, (select ename from emp where empno = e.mgr) �쵼
from emp e;/*�����e�������emp��ı���*/

select ename, dname from emp,dept where job='CLERK' and emp.deptno = dept.deptno;

select ename, (select dname from dept where deptno=e.deptno) dname
from emp e where job='CLERK';

/* on��ʾ���� */
select ename, dname from emp  LEFT JOIN dept on emp.deptno = dept.deptno where job='CLERK';

/* in��ʾ������������棬in��ʾ�Ƿ�����������У�����������Ͼ���no in*/
/* �Ӳ�ѯ������where�Ӿ��� */
select ename, (select dname from dept where deptno=e.deptno) dname
from emp e where job='CLERK' and deptno in (select deptno from dept);

/* �Ӳ�ѯֻ��1����¼���Ҹü�¼��ֻ��1���ֶΣ�������ô�� �����ж���ֶ�������ô��*/
select * from emp where sal > (select sal from emp where ename='SMITH');
select * from emp e where hiredate < (select hiredate from emp where empno=e.mgr);

/* (select ename, (select dname from dept where deptno=e.deptno) dname
from emp e where job='CLERK')�Ӳ�ѯ�ı�����a ���Ҹ��Ӳ�ѯ����ǳ�����from�����*/
select ename, dname
from
(select ename, (select dname from dept where deptno=e.deptno) dname
from emp e where job='CLERK') a
where dname is not null;

/* ��ѯн��С������Աĳ��Ա����Ա����Ϣ */
select * from emp WHERE
sal < any (select sal from emp where job='SALESMAN');
/* ����ȼ��� */
/* select max(sal) from emp where job='SALESMAN'����Ա������¼ */
/* max�ǾۺϺ��� */
select * from emp WHERE
sal < (select max(sal) from emp where job='SALESMAN');

/* ��ѯн�������������Ա��Ա����Ϣ */
select * from emp WHERE
sal > all (select sal from emp where job='SALESMAN');

/* �г��롰SCOTT��������ͬ����������Ա���� */
select * from emp e where EXISTS
(
select * from emp where ename='SCOTT' and e.job = job
);

/* select job from emp where ename='SCOTT'�ҵ�SCOTT�Ĺ������� */
select * from emp where job =(select job from emp where ename='SCOTT');



����ʮ����
/* ͳ�����зǿ��ֶ� */
select count(comm) as ��¼�� from emp;

/* ͳ�������У��������ֶε���������һ�ж���null��Ҳ����һ����¼ */
select count(*) as ��¼�� from emp;

/* ͳ�������У�����ɨ��������ף������ǿյģ�Ҳ����һ�� */
select count(0) as ��¼�� from emp;

/* ͳ�������У�����ɨ��������ף������ǿյģ�������һ�� */
select count(empno) as ��¼�� from emp;

select avg(sal) as ƽ��н��,
max(sal) as ���н��,
min(sal) as ���н��,
sum(sal) as н���ܺ�
from emp;

/* ͳ�Ƹ������ŵ�Ա���� */
/* ����deptno���з��� */
select deptno, count(*), from emp group by deptno;
/* ����֮���������HAVING����Ҫ��where */
select deptno, count(*) cn from emp group by deptno HAVING cn > 3;
/* ��cn���н��� */
select deptno, count(*) cn from emp group by deptno HAVING cn > 3 ORDER BY cn desc;

/*�г���������Ϣ�Լ�����������  */
/* ��emp����з����������������� */
select *, (select count(*) from emp group by deptno HAVING deptno = dept.deptno) total 
from dept;

/* ifnull�жϲ�ѯ���ֶ��Ƿ�Ϊ�գ�Ϊ�������һ��0 */
select *, ifnull((select count(*) from emp group by deptno HAVING deptno = dept.deptno), 0) total 
from dept;

/* ��ѯ��н��ɱ���ߵĲ��ŵĲ��źźͲ������� */
/* �����ӵķ�ʽ�� ��dept���emp��������һ�𣬵���ֻ��ȡ����dept.deptno, dept.dname�����ֶ�*/
/* select dept.deptno, dept.dname
from dept�����ҳ����źźͲ�������

Ϊʲôsum(sal)ȡ�����ܹ��ʣ���Ϊ�������group by dept.deptno, dept.dname�����ˣ�select���ֶ�ֻ���Ƿ���group by���ֶ�
select dept.deptno, dept.dname, sum(sal)
from dept, emp
where dept.deptno=emp.deptno
group by dept.deptno, dept.dname
 */
 /* select sum(sal) from emp group by deptno��ÿ�����ŵ���н�ʣ��ǶԲ��Ž��з��飬�ж�����¼�ģ��Ӳ�ѯ */
select dept.deptno, dept.dname
from dept, emp
where dept.deptno=emp.deptno
group by dept.deptno, dept.dname
HAVING sum(sal) >= all (select sum(sal) from emp group by deptno)

/* ���Ӳ�ѯ�ķ�ʽ :select sum(sal) from emp group by deptno ������һ���Ӳ�ѯ
select dept.deptno, dept.dname
from dept, emp
where dept.deptno=emp.deptno
group by dept.deptno, dept.dname
HAVING sum(sal) >=(
select t.total
from
(select sum(sal) total from emp group by deptno) t
)

Ȼ����������ֵ
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


����ʮ����
CASE value WHEN [compare-value] THEN result [WHEN [compare-value] THEN result ...] [ELSE result] END

CASE WHEN [condition] THEN result [WHEN [condition] THEN result ...] [ELSE result] END 

/* from��MySql5.1�ο��ֲ��е�12.2. �������̺�����eg */
/* when�����1��CASE�����1���бȽϣ�����������one*/
/* CASE�����1�����������ݿ��е�ĳ���ֶ� */
SELECT CASE 1 WHEN 1 THEN 'one' 
WHEN 2 THEN 'two' ELSE 'more' END;

/* CASE����1>0�����true */
SELECT CASE WHEN 1>0 THEN 'true' ELSE 'false' END;

/* emp���salgrade��Ҫ������һ��ʹ�����Ӳ�ѯ 
��������������͹��ʺ���߹���֮��

select ename, sal, grade
from emp, salgrade
where sal between losal and hisal;

*/

select ename Ա��, sal н��, case grade when 1 then 'һ��'
when 2 then '����'
when 3 then '����'
when 4 then '�ļ�'
when 5 then '�弶'
end �ȼ�
from emp, salgrade
where sal between losal and hisal

/* ASCII(str) 
����ֵΪ�ַ���str �������ַ�����ֵ��
 */
SELECT ASCII('2a');
SELECT ASCII('a2');
/* BIN(N) 
����ֵΪN�Ķ�����ֵ���ַ�����ʾ
 */
SELECT BIN(12);
/* BIT_LENGTH(str) 
����ֵΪ�����Ƶ��ַ���str ���ȡ�
 */
/* ÿ���ַ�8λ�����صľ���32λ */
SELECT BIT_LENGTH('text');

/* CHAR(N,... [USING charset]) 
CHAR()��ÿ������N���Ϊһ���������䷵��ֵΪһ��������Щ�����Ĵ���ֵ���������ַ����ַ�����NULLֵ��ʡ�ԡ� 
 */
SELECT CHAR(77,121,83,81,'76');
/* �����һ���� */
SELECT CHAR(77,121,83,81,76);

/* CHAR_LENGTH(str) 
����ֵΪ�ַ���str �ĳ��ȣ����ȵĵ�λΪ�ַ� */

/* CONCAT(str1,str2,...)                        
���ؽ��Ϊ���Ӳ����������ַ�����
 */
mysql> SELECT CONCAT('My', 'S', 'QL');
        -> 'MySQL'


SELECT 3+5;
SELECT 3/5;

SELECT ABS(-32);

select now();

SELECT DATE_ADD('1998-02-02', INTERVAL 31 DAY);

SELECT DATE_ADD('1998-02-02', INTERVAL 28 DAY);
/* ���һ�� */
SELECT adddate('1998-02-02', INTERVAL 28 DAY);
/* ���һ�� */
SELECT adddate('1998-02-02', 28);

/* DATEDIFF�����������ڵ�ʱ������Ϊʱ���*/
select DATEDIFF(now(),'2014-02-01');
select DATEDIFF('2014-02-01','2014-03-01');

/* DATE_FORMAT��ʱ���ʽ�� */
/* '%H:%i:%s'��ʾֻȡ��ʱ���� */
select DATE_FORMAT(now(), '%H:%i:%s');

select DATE_FORMAT(now(), '%Y%M%D');

select DATE_FORMAT(now(), '%Y%m%d');