- [Ŀ��](#Ŀ��)
- [�����ļ�����](#�����ļ�����)
  - [��������](#��������)
  - [�������](#�������)


# Ŀ��

���һ�� priority_queue �࣬ʵ�����¹��ܣ�

1. ��������

    - ���캯������ʼ�� priority_queue ʵ��
    - ����������������Դ��ȷ�����ڴ�й¶

2. ���Ĺ���

    - ��Ԫ����ӵ� priority_queue ��
    - ���� priority_queue �е����Ԫ��
    - ��ȡ priority_queue �е����Ԫ��
    - ��ȡ priority_queue ��Ԫ�صĸ���
    - �ж� priority_queue �Ƿ�Ϊ��


# �����ļ�����


## ��������

�����������룬��һ��Ϊ������ N, ��������� N ���������С�<br>
������ N �У�ÿ�а���һ����������ʽΪ [operation] [parameters] �������������£�<br>

```
push ���
��ʽ��push [element]
���ܣ��� element ��ӵ� priority_queue ��

pop ���
��ʽ��pop
���ܣ����� priority_queue �е����Ԫ��

top ���
��ʽ��top
���ܣ����� priority_queue �е����Ԫ��

empty ���
��ʽ��empty
���ܣ���� priority_queue �Ƿ�Ϊ��

size ���
��ʽ��size
���ܣ����� priority_queue �Ĵ�С
```


## �������

���Ϊÿ������ִ�к�Ľ�������������ʽ���£�

```
push ��������
pop ��������
top ������һ����������ռһ�У����� priority_queue ������Ԫ�أ���� priority_queue Ϊ�գ������ null
empty ���Ϊ����� true����Ϊ����� false�������ռһ��
size ������һ����������ռһ�У����� priority_queue �Ĵ�С
```