# suttongit
# suttongit
 	
 	###  **程序设计报告:** 
 	
 	姓名：苏童  班级：软件193 学号：2019082316
 	 
 	###  **题目：** 
 	
 	通讯录管理程序
 	
 	###  **要求：** 
 	
 	本程序用来管理个人通信信息。功能要求实现：添加，删除，修改显示联系人基本信息（姓名，职务，手机，email等），可实现分类查找（通过搜索姓名，职务，手机,email等）， 按照姓名排序来输出各个记录信息。
 	
 	###  **设计思路：** 
 	
 	用单链表的操作来实现增删改查联系人，在主函数里增加可视化菜单，利用主函数调用各个函数，完成所有功能的实现。
 	
 	###  **数据结构：** 
 	
 	   定义了一个包含编号，姓名，职业，电话，邮箱的结构体，作为单链表的数据域，指针域来存储下一个指针的地址，定义联系人的各信息均为字符串型。
 	
 	###  **流程图：** 
 	
 	![输入图片说明](https://images.gitee.com/uploads/images/2020/0311/184534_b7b290b9_6511752.png "无标题.png")
 	 
 	
 	### **功能函数介绍：** 
 	
 	1. //初始化链表 
 	PNode initialize() ;
 	2. //尾插法创建一个新的结点 
 	void insert(PNode p) ;
 	3. //将传入的结点进行初始化处理 
 	void emptynode(PNode p);
 	4. //判断传入的指针是否为空 
 	void judge_empty(PNode p) ;
 	5. //在链表尾部添加联系人功能 
 	void input(PNode phead); 
 	6. //显示当前结点联系人创建情况 
 	void displaycurrent(PNode phead);
 	7. //实现分类查找联系人 
 	void search(PNode phead);
 	8. //删除联系人函数模块 
 	void del(PNode phead);
 	9. //显示所有已经创建的联系人 
 	void display_record(PNode phead);
 	10. //修改联系人函数 
 	void revise(PNode phead);
 	11. //将目前已有的联系人进行排序 
 	void sort(PNode phead);
 	12.//菜单页面函数 
 	void menu();
 	
 	
 	
 	
 	
 	
 	
 	
 	
 	 
 	
 	### 部分功能展示图：
 	
 	![菜单界面](https://images.gitee.com/uploads/images/2020/0311/173543_f4b054ec_6511752.png "批注 2020-03-11 173500.png")
 	![输入联系人](https://images.gitee.com/uploads/images/2020/0311/174629_fa3bbb63_6511752.png "批注 2020-03-11 173821.png") 
 	![输入图片说明](https://images.gitee.com/uploads/images/2020/0311/174808_9ecba5ef_6511752.png "批注 2020-03-11 174112.png")
 	![输入图片说明](https://images.gitee.com/uploads/images/2020/0311/174826_a0ec690e_6511752.png "批注 2020-03-11 174245.png")
 	![输入图片说明](https://images.gitee.com/uploads/images/2020/0311/174901_eb209268_6511752.png "批注 2020-03-11 174322.png")
 	![输入图片说明](https://images.gitee.com/uploads/images/2020/0311/174915_3dde0233_6511752.png "批注 2020-03-11 174351.png")
 	![输入图片说明](https://images.gitee.com/uploads/images/2020/0311/174926_d159b086_6511752.png "批注 2020-03-11 174428.png")
 	![输入图片说明](https://images.gitee.com/uploads/images/2020/0311/175006_bf3e0a30_6511752.png "批注 2020-03-11 174509.png")
 	
 	
 	
 	
 	
 	
 	 
 	
 	### 遇到的问题和处理方法：
 	在做这次课设之前，我的C语言基础非常一般，对链表的掌握程度几乎为零，为此在课设开始之前，我通过翻阅课本，看视频，找资料，来弥补自己的知识漏洞，在一开始，我百思不得其解该如何用链表实现这些功能，后来我明白链表有数据域和指针域，由结点首尾相连形成单链表，新节点插入链表中有两种方法，前插法和尾插法，我就是通过尾插法来实现添加联系人信息功能；删除联系人的功能我想了想，发现可以通过遍历链表，找到与删除相匹配的字符串，然后用free()则可实现删除功能，其中困惑我最久的便是如何将联系人通过姓氏进行排序，后来我通过查阅资料发现可以用strcmp函数来对两个名字进行比较，用一个临时的ptemp指针作为桥梁，将信息通过strcpy函数进行交换，在我的整个编写代码过程中遇到了各种调试出错的情况，通过复制下来error的内容上网查找，解决了一个个困惑我的bug。
 	
 	### 总结与感悟：
 	  通过这次课设，我看清自己和班级里的代码大神的差距很大，所以在接下来我还要继续努力，把C语言的基础打好，认真写每一行代码，脚踏实地认认真真学习知识，数学和英语的重要性不可言喻。通过这次课设，我的收获是学会了单链表的使用，学会了如何用git 来做版本记录，这次课设的收获让我明白，自己距离未来的目标差的太远了，所以我要继续努力，笨鸟先飞，跟紧班级里程序大神的节奏，早日完成对编码水平的提高，提高自己的工作效率，严格遵照规范来打码，加油吧。
 	
 	
 	
 	
 	
