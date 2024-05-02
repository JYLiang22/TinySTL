# Ŀ��

���һ�� unordered_map �࣬ʵ�����¹��ܣ�

1. ��������

    - ���캯������ʼ�� unordered_map ʵ��
    - ����������������Դ��ȷ�����ڴ�й¶

2. ���Ĺ���

    - �� unordered_map �в���һ��Ԫ��
    - �� unordered_map ��ɾ��Ԫ��
    - �ж�һ��Ԫ���Ƿ��� unordered_map ��
    - �ж� unordered_map �Ƿ�Ϊ��
    - ��ȡ unordered_map �Ĵ�С


# �����ļ�����


## ��������

�����������룬��һ��Ϊ������ N, ���������� N ���������С�<br>
������ N �У�ÿ�а���һ����������ʽΪ [operation] [parameters] �������������£�<br>

```
insert ���
��ʽ��insert [key] [value]
���ܣ��� map ������ key-value ��ֵ�ԣ������Ӧ�� key �Ѿ����ڣ��򲻽����κβ���

erase ���
��ʽ��erase [key]
���ܣ�ɾ�� unordered_map �� key ��Ӧ�ļ�ֵ�ԣ���� key �����ڣ��򲻽����κβ���

find ���
��ʽ��find [key]
���ܣ���ѯ unordered_map �Ƿ���� key ��Ӧ�ļ�ֵ��

empty ���
��ʽ��empty
���ܣ��ж� unordered_map �Ƿ�Ϊ��

size ���
��ʽ��size
���ܣ���ȡ unordered_map �Ĵ�С
```


## �������

���Ϊÿ������ִ�к�Ľ�������������ʽ���£�

```
insert ��������
erase ��������
empty ������ unordered_map Ϊ�գ������ true��������� false�������ռһ��
size ������һ����������ռһ�У����� unordered_map �Ĵ�С
find ������ key ���ڣ������ true��������� false�������ռһ��
```


# ���׼�������

��C++��׼���е�unordered_map��ȣ�һ���򻯰汾��ʵ�ֿ��ܴ�����������<br>
����Զ���� Unordered_map ���ڹ������� STL (Standard Template Library) �е� std::unordered_map ���ƣ�������֮���м����ؼ�����������һЩǱ�ڵĲ��죺

1. �쳣��ȫ�ԣ�

    - std::unordered_map �ṩ���쳣��ȫ��֤���ر����ڲ��������׳��쳣������¡����磬������ Key �� Value �Ĺ��캯����ֵ���������׳��쳣ʱ��std::unordered_map ��ȷ�����쳣����ʱ���ƻ��������ݡ�
    - �Զ��� Unordered_map �����û����Ӧ���쳣��ȫ���ƣ����� HashTable ���ڲ��ṩ�����ֱ�����
  
2. ������֧�֣�

    - std::unordered_map �ṩ������ͳ�����������ʹ���û����Ա��������е�����Ԫ�ء�
    - Unordered_map ��û���ṩ��������ʵ�ֻ�ӿڣ����������û��ڼ����Ͻ��е�����������

3. �����������Ժ�������

   - std::unordered_map �ṩ��һϵ�������ĳ�Ա���������� emplace, emplace_hint, find, equal_range, bucket, load_factor, rehash �ȡ�
   - �Զ��� Unordered_map ��ĳ�Ա�������٣������������� STL ��Լ����ͬ�����磬find ��������һ������ֵ�����ǵ�������

4. �ڴ������

    - std::unordered_map ʹ���˸߶��Ż����ڴ�������������ڴ棬�����ṩ��Ч���ڴ�ʹ�ú����á�
    - �Զ��� Unordered_map ����ڴ����ȡ���� HashTable ���ʵ�֣�����û��ͬ�����Ż���
    
5. ���ܣ�

    - std::unordered_map �����˹㷺���Ż����ṩ������ܣ��ر����ڹ�ϣ��������ײ������Է��档
    - �Զ��� Unordered_map ������ܱ��ֽ�ȡ���� HashTable ���ʵ��ϸ�ڡ�

6. ����ֲ�Ժͼ����ԣ�

    - std::unordered_map �� C++ ��׼��һ���֣�����������б�׼���ݵı���������Ϊһ�¡�
    - �Զ��� Unordered_map ������ڲ�ͬ��������ƽ̨�ϱ��ֲ�һ�£������ر�ע���ƽ̨�����ԡ�

7. ģ�������

    - std::unordered_map �����û�ָ����ϣ�����ͼ��ȽϺ�����
    - �Զ��� Unordered_map ���ƺ�û���ṩ����ѡ�������ֱ������ HashTable �Ĺ�ϣ�����ͱȽ��߼���

8. Ĭ�Ϲ���Ԫ�أ�

    - �� std::unordered_map �У�ʹ���±����������һ�������ڵļ����Զ�����һ���ü�����Ŀ����Ĭ�Ϲ�����ֵ��
    - �Զ��� Unordered_map ���±������ʵ��Ҳ�ƺ��ṩ�����Ƶ���Ϊ������������ HashTable ��� insertKey ������ʵ�֡�

9. �������Ʋ�����

    - std::unordered_map �����˿������캯�����ƶ����캯����������ֵ��������ƶ���ֵ��������Լ�����������
    - �Զ��� Unordered_map �����û���ṩ������Щ�������Ʋ������������� HashTable ���ʵ�֡�