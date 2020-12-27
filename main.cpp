#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <math.h>
#pragma comment(lib,"Winmm.lib")
#define width 960
#define high 580// 全局变量
float jumplimit;//跳跃高度限制
float jumpleft = 1;
float jumpright = 0;
int if_rocket;
int if_ci;
int if_lose;
int brick1;
int brick2;
float position_brick_x[5];
float position_brick_y[5];//砖块坐标
float downlimit;
float downlimit_human;
float i;//第一个显示控制
float j;//第二个显示控制
float brick3, brick4, brick5, brick6, brick7, brick8;
float position_human_x;
float position_human_y;  //小人坐标
float position_princess_x;
float position_princess_y;//公主坐标
float position_rocket_y;//火箭坐标
float position_rocket_x;
float position_rocket_y1;//火箭坐标
float position_rocket_y2;//火箭坐标
float position_rocket_vx;//火箭速度
float position_guai1_x;
float position_guai1_y;
float position_guai2_x;
float position_guai2_y;
float brick_x;
float ci_ground_x, ci_right_x;
float ci_ground_show;
float go_x;
float rocket1_x;
float rocket2_x;
float rocketup_y;
float k;
char input;
float left_i;
float right_i;
float if_inputleft;  //判断向左
float if_inputright; //判断向右
float if_victory;
int stage;
float ground;
float ground_guai;
int flag;
int bk_x;
int guan;
IMAGE img_human;
IMAGE img_human1;
IMAGE img_human2;
IMAGE img_princess1;
IMAGE img_princess2;
IMAGE img_victory;
IMAGE img_rocket1;
IMAGE img_lose;
IMAGE img_lose2;
IMAGE img_start;
IMAGE img_guanyu;
IMAGE img_guanka;
IMAGE img_first;
IMAGE img_second;
IMAGE img_ci;
IMAGE img_chaoxiao;
IMAGE img_guai1;
IMAGE img_guai2;
IMAGE img_brick1;
IMAGE img_go;
IMAGE img_go2;
IMAGE img_ci_ground;
IMAGE img_ci_ground2;
IMAGE img_ci_left;
IMAGE img_yaoshi;
IMAGE img_rocket;
IMAGE img_rocket2;
IMAGE img_rocket3;
IMAGE img_rocket4;
IMAGE img_rocketup;
IMAGE img_rocketup2;
IMAGE img_yun;
IMAGE img_ci_right;
IMAGE img_brick;
IMAGE img_brick2;
IMAGE img_renyuan;
IMAGE img_caozuo;
IMAGE img_shuoming;
IMAGE img_muyi;
IMAGE img_muer;
IMAGE img_musan;
IMAGE img_musi;
void startup_all() // 数据初始化
{
	flag = 10;
	if_victory = 0;
	if_lose = 0;
	stage = 0;
	bk_x = 0;
	guan = 0;
	loadimage(&img_start, _T(".\\图片\\start.jpg"));
	loadimage(&img_guanka, _T(".\\图片\\guanka.jpg"));
	loadimage(&img_guanyu, _T(".\\图片\\guanyu.jpg"));
	loadimage(&img_lose, _T(".\\图片\\lose.jpg"));
	loadimage(&img_lose2, _T(".\\图片\\lose2.jpg"));
	loadimage(&img_victory, _T(".\\图片\\victory.jpg"));
	loadimage(&img_renyuan, _T(".\\图片\\renyuan.jpg"));
	loadimage(&img_caozuo, _T(".\\图片\\caozuo.jpg"));
	loadimage(&img_shuoming, _T(".\\图片\\shuoming.jpg"));

	loadimage(&img_muyi, _T(".\\图片\\muyi.jpg"));
	loadimage(&img_muer, _T(".\\图片\\muer.jpg"));
	loadimage(&img_musan, _T(".\\图片\\musan.jpg"));
	loadimage(&img_musi, _T(".\\图片\\musi.jpg"));
	mciSendString(_T("open .\\图片\\home.mp3 alias homemusic"), NULL, 0, NULL);//背景音乐
	mciSendString(_T("play homemusic repeat"), NULL, 0, NULL);
	initgraph(width, high);
	setbkcolor(WHITE);
	cleardevice();
}
void startup_first()
{
	position_human_x = 150;
	position_human_y = 420;  //小人坐标
	position_rocket_x = 50;
	position_rocket_y = high - 150;//火箭坐标
	left_i = 2;
	right_i = 2;
	if_inputleft = 1;  //判断向左
	if_inputright = 1; //判断向右
	bk_x = 0;//显示背景区域
	i = 0;//控制砖块显现
	j = 0;//控制钥匙显现
	k = 0;
	brick_x = 220;//砖块坐标
	go_x = 280;
	guan = 0;
	brick1 = 0;
	brick2 = 0;
	brick3 = 0;
	brick4 = 0;
	brick5 = 0;
	brick6 = 0;
	ci_ground_x = 130;
	ci_ground_show = 0;
	rocket1_x = 1000;
	rocket2_x = -400;
	rocketup_y = 600;//火箭坐标
	if_lose = 0;//为1代表失败
	if_victory = 0;//为1代表胜利
	loadimage(&img_first, _T(".\\图片\\first.jpg"));
	loadimage(&img_rocket, _T(".\\图片\\rocket.jpg"));
	loadimage(&img_rocket2, _T(".\\图片\\rocket2.jpg"));
	loadimage(&img_rocket3, _T(".\\图片\\rocket3.jpg"));
	loadimage(&img_rocket4, _T(".\\图片\\rocket4.jpg"));
	loadimage(&img_rocketup, _T(".\\图片\\rocketup.jpg"));
	loadimage(&img_rocketup2, _T(".\\图片\\rocketup2.jpg"));
	loadimage(&img_yaoshi, _T(".\\图片\\yaoshi.jpg"));
	loadimage(&img_ci_ground, _T(".\\图片\\ci_ground.jpg"));
	loadimage(&img_ci_ground, _T(".\\图片\\ci_ground2.jpg"));
	loadimage(&img_ci_right, _T(".\\图片\\ci_right.jpg"));
	loadimage(&img_ci_left, _T(".\\图片\\ci_left.jpg"));
	loadimage(&img_yun, _T(".\\图片\\yun.jpg"));
	loadimage(&img_human, _T(".\\图片\\move.jpg"));
	loadimage(&img_human2, _T(".\\图片\\move2.jpg"));
	mciSendString(_T("close homemusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(_T("open .\\图片\\start.mp3 alias startmusic"), NULL, 0, NULL);//背景音乐
	mciSendString(_T("play startmusic repeat"), NULL, 0, NULL);  // 循环播放
}
void startup_second()
{
	position_human_x = 100;
	position_human_y = 420;  //小人坐标
	position_rocket_x = 900;
	position_rocket_vx = 1.5;
	position_rocket_y1 = 50;
	position_rocket_y2 = 100;//火箭坐标
	position_princess_x = 750;
	position_princess_y = 420;//公主坐标
	position_guai1_x = 540;
	position_guai1_y = 255;
	position_guai2_x = 590;
	position_guai2_y = 420;//小怪坐标
	if_victory = 0;//为1代表胜利
	bk_x = 0;//显示的背景坐标
	if_lose = 0;//为1代表失败
	if_rocket = 0;//是否显示火箭
	if_ci = 0;//是否显示刺
	brick1 = 0;
	brick2 = 0;//是否显示砖块
	guan = 0;//第几幕背景
	left_i = 2;
	right_i = 2;
	if_inputleft = 1;  //判断向左
	if_inputright = 1; //判断向右
	loadimage(&img_second, _T(".\\图片\\second.jpg"));
	loadimage(&img_human2, _T(".\\图片\\move.jpg"));
	loadimage(&img_human1, _T(".\\图片\\move2.jpg"));
	loadimage(&img_princess2, _T(".\\图片\\princess.jpg"));
	loadimage(&img_princess1, _T(".\\图片\\princess2.jpg"));
	loadimage(&img_rocket1, _T(".\\图片\\rocket1.jpg"));
	loadimage(&img_ci, _T(".\\图片\\ci.jpg"));
	loadimage(&img_chaoxiao, _T(".\\图片\\chaoxiao.jpg"));
	loadimage(&img_guai2, _T(".\\图片\\guai.jpg"));
	loadimage(&img_guai1, _T(".\\图片\\guai2.jpg"));
	loadimage(&img_brick1, _T(".\\图片\\brick.jpg"));
	mciSendString(_T("close homemusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(_T("open .\\图片\\start.mp3 alias startmusic"), NULL, 0, NULL);//背景音乐
	mciSendString(_T("play startmusic repeat"), NULL, 0, NULL);  // 循环播放
}
void show_start()  // 显示画面
{
	if (flag == 10)
	{
		putimage(0, 0, &img_muyi);
	}
	if (flag == 11)
	{
		putimage(0, 0, &img_muer);
	}
	if (flag == 12)
	{
		putimage(0, 0, &img_musan);
	}
	if (flag == 13)
	{
		putimage(0, 0, &img_musi);
	}
	if (flag == 0)//进入开始界面
	{
		putimage(0, 0, &img_start);
	}
	else if (flag == 2)//进入关于界面
	{
		putimage(0, 0, &img_guanyu);
	}
	else if (flag == 1)//进入选择关卡界面
	{
		putimage(0, 0, &img_guanka);
	}
	else if (flag == 5)//进入操作界面
	{
		putimage(0, 0, &img_caozuo);
	}
	else if (flag == 6)//进入作者界面
	{
		putimage(0, 0, &img_renyuan);
	}
	else if (flag == 8)//进入说明界面
	{
		putimage(0, 0, &img_shuoming);
	}
	else if (flag == 3)//进入第一关
	{
		stage = 1;
	}
	else if (flag == 4)//进入第二关
	{
		stage = 2;
	}


}
void xian()
{

	if (guan == 0)//第一关第一幕是在特定的坐标下地板高度
	{
		if ((position_human_x > 180 && position_human_x < 230 && position_human_y < 260 && position_human_y>200) && (i == 1))
			ground = 230;
		if ((position_human_x > 230 && position_human_x < 550 && position_human_y < 200) && (i == 1))
			ground = 170;
		if (position_human_x > 610)
			ground = 420;
		if (position_human_x > 160 && position_human_x < 270 && position_human_y < 260)
			ground = 230;
		if (position_human_x <= 160)
			ground = 420;

	}
	if (guan == 1)//第一关第二幕是在特定的坐标下地板高度
	{
		if (position_human_x > 125 && position_human_x < 426 && position_human_y < 300 && position_human_y > 190)
		{
			ground = 280;
		}
		if (position_human_x >= 200 && position_human_x <= 350 && position_human_y < 190)
		{
			ground = 140;
		}
		if ((position_human_x < 200 && position_human_x>125) || (position_human_x > 350 && position_human_x < 426) && position_human_y < 190)
		{
			ground = 280;
		}
		if (position_human_x > 530 && position_human_x < 650 && position_human_y < 300)
		{
			ground = 270;
		}
	}

	if (guan == 2)//第一关第三幕是在特定的坐标下地板高度
	{
		if (position_human_x < 65)
		{
			ground = 420;
		}
		if (position_human_x >= 65 && position_human_x < 170 && position_human_y < 300)
		{
			ground = 270;
		}
		if (position_human_x >= 160 && position_human_x <= 280 && position_human_y < 170)
		{
			ground = 110;
		}
		if (position_human_x >= 400 && position_human_x <= 510 && position_human_y < 300)
		{
			ground = 270;
		}
		if (position_human_x >= 160 && position_human_x < 400 && brick6 != 1 && position_human_y < 230)
		{
			ground = 420;
		}
		if (position_human_x >= 280 && position_human_x < 430)
		{
			ground = 420;
		}
	}
}
void show_first()//第一关初始显示画面
{
	clearrectangle(0, 0, width, high);
	putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, NOTSRCERASE);//小人图片
	putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 50, SRCINVERT);//小人图片
	putimage(0, 0, 1000, 600, &img_first, 0, 0);
}
void show_second()//第二关初始显示画面
{

	clearrectangle(0, 0, width, high);
	putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 50, NOTSRCERASE);
	putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, SRCINVERT);
	putimage(0, 0, 3000, 1000, &img_second, 0, 0);


}
void lose1()
{
	brick6 = 0;//取消显示砖块
	if (stage == 2)//第二关失败动画
	{
		putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 0, NOTSRCERASE);
		putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 0, SRCINVERT);
	}
	if (stage == 1)//第一关失败动画
	{
		putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 0, NOTSRCERASE);
		putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 0, SRCINVERT);
	}

	mciSendString(_T("close startmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(_T("open .\\图片\\lose.mp3 alias losemusic"), NULL, 0, NULL);//背景音乐
	mciSendString(_T("play losemusic  "), NULL, 0, NULL);  // 循环播放


}
void lose2()
{
	//失败动画
	putimage(0, 0, 450, 271, &img_lose2, 0, 0, NOTSRCERASE);
	putimage(0, 0, 450, 271, &img_lose, 0, 0, SRCINVERT);
	//Sleep(1000);
}
void rocketup()//控制火箭向上运动
{
	rocketup_y -= 20;
	if (fabs(position_human_x - 480) < 20 && fabs(position_human_y - rocketup_y) < 20)//失败条件
	{
		if_lose = 1;
	}
	putimage(480, rocketup_y, &img_rocketup2, NOTSRCERASE);
	putimage(480, rocketup_y, &img_rocketup, SRCINVERT);
}
void rocketmove()//控制火箭左右移动
{
	rocket1_x -= 20;
	rocket2_x += 20;
	if (fabs(rocket1_x - position_human_x) < 20 || fabs(rocket2_x - position_human_x) < 20)//失败条件
	{


		if_lose = 1;
	}
}
void victory()
{
	brick6 = 0;//放弃显示砖块
	putimage(0, 0, 450, 271, &img_victory, 0, 0);
	mciSendString(_T("close startmusic"), NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(_T("open .\\图片\\victory.mp3 alias victorymusic"), NULL, 0, NULL);//背景音乐
	mciSendString(_T("play victorymusic"), NULL, 0, NULL);  // 循环播放
}
void chonghua_first()//清屏后重画
{

	putimage(0, 0, 3000, 1000, &img_first, bk_x, 0);//背景


	putimage(rocket1_x, 420, &img_rocket2, NOTSRCERASE);
	putimage(rocket1_x, 420, &img_rocket, SRCINVERT);
	putimage(rocket2_x, 360, &img_rocket4, NOTSRCERASE);
	putimage(rocket2_x, 360, &img_rocket3, SRCINVERT);
	putimage(480, rocketup_y, &img_rocketup2, NOTSRCERASE);
	putimage(480, rocketup_y, &img_rocketup, SRCINVERT);//火箭
	if (k == 1)//显示带刺的云并作为失败条件
	{
		putimage(480, 24, &img_yun);


		if_lose = 1;
	}
	if (position_human_x >= 400 && guan == 2)//跳到第二个大烟囱上
	{
		rocketup();
	}
	if (guan == 1 && j == 0)//第二部分显示钥匙
	{
		putimage(270, 280, &img_yaoshi);
	}
	if (ci_ground_show == 1)//当碰到草地时显示陷阱
	{
		putimage(ci_ground_x, 445, &img_ci_ground);


		if_lose = 1;


	}
	if (j == 1)//当碰到钥匙时显示陷阱
	{
		putimage(400, 175, &img_ci_left);
		putimage(180, 175, &img_ci_right);
	}
	if (guan == 2)//第三个部分，在两个大烟囱之间显示砖块
	{
		if (brick1 == 1)
		{
			loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
			putimage(190, 315, 50, 50, &img_brick, 0, 0);
		}
		if (brick2 == 1)
		{
			loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
			putimage(240, 315, 50, 50, &img_brick, 0, 0);
		}
		if (brick3 == 1)
		{
			loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
			putimage(290, 315, 50, 50, &img_brick, 0, 0);
		}
		if (brick4 == 1)
		{
			loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
			putimage(340, 315, 50, 50, &img_brick, 0, 0);
		}
		if (brick5 == 1)
		{
			loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
			putimage(390, 315, 50, 50, &img_brick, 0, 0);

		}
		if (brick6 == 1)
		{
			loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
			putimage(180, 165, 50, 50, &img_brick, 0, 0);
			putimage(230, 165, 50, 50, &img_brick, 0, 0);
		}
	}
	if (i == 1 && guan == 0)//第一部分显示陷阱
	{
		loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
		putimage(brick_x, 280, 50, 50, &img_brick, 0, 0);
		loadimage(&img_go, _T(".\\图片\\go.jpg"));
		loadimage(&img_go2, _T(".\\图片\\go2.jpg"));
		putimage(go_x, 220, 300, 350, &img_go2, 0, 0, NOTSRCERASE);
		putimage(go_x, 220, 300, 350, &img_go, 0, 0, SRCINVERT);
	}




	if (brick1 == 1 && brick2 == 1 && brick3 == 1 && brick4 == 1 && brick5 == 1)//第三部分砖块都出现了，显示陷阱
	{
		rocketmove();
	}
	if (position_human_y == 600 && guan == 0)//小人掉落，失败
	{


		if_lose = 1;

	}
	if (j == 1 && (position_human_x < 220 || position_human_x>350) && guan == 1)//失败条件
	{


		if_lose = 1;

	}
	if (fabs(rocket1_x - position_human_x) < 20 || fabs(rocket2_x - position_human_x) < 20 && guan == 2)//碰到火箭失败
	{


		if_lose = 1;
	}
	if (fabs(position_human_x - 480) < 10 && fabs(position_human_y - rocketup_y) < 20 && guan == 2)//碰到火箭失败
	{


		if_lose = 1;
	}
	if (position_human_x > 800 && position_human_x < 900 && guan == 2)//碰到公主胜利
	{
		if_victory = 1;

	}
	if (if_lose == 1)
	{
		lose1();
		lose2();

	}
	if (position_human_x > 800 && guan == 2)
		if_victory = 1;
	if (if_victory == 1)
		victory();
}
void chonghua_second()//第二关清屏重画
{
	putimage(0, 0, 3000, 1000, &img_second, bk_x, 0);//重画背景
	if (position_human_x >= 440 && position_human_x <= 490 && jumplimit == 0 && guan == 2 && position_human_y > 250 && position_human_y < 350)//满足条件显示砖块
		brick1 = 1;
	if (position_human_x >= 150 && position_human_x <= 600 && position_human_y >= 400 && guan == 1)//失败条件
		if_lose = 1;
	if (position_human_x >= position_guai2_x - 45 && position_human_x <= position_guai2_x + 20 && position_human_y >= position_guai2_y - 40 && position_human_y <= position_guai2_y + 40 && guan == 2)//失败条件
	{
		putimage(position_guai2_x, position_guai2_y, 50, 50, &img_guai1, 0, 0, NOTSRCERASE);
		putimage(position_guai2_x, position_guai2_y, 50, 50, &img_guai2, 0, 0, SRCINVERT);
		if_lose = 1;
	}
	if (position_human_x >= position_guai1_x - 45 && position_human_x <= position_guai1_x + 40 && position_human_y >= position_guai1_y - 40 && position_human_y <= position_guai1_y + 40 && guan == 1)//失败条件
	{
		putimage(position_guai1_x, position_guai1_y, 50, 50, &img_guai1, 0, 0, NOTSRCERASE);
		putimage(position_guai1_x, position_guai1_y, 50, 50, &img_guai2, 0, 0, SRCINVERT);
		if_lose = 1;
	}

	if (position_human_x >= 495 && position_human_x <= 650 && position_human_y == 110 && guan == 0)//满足条件显示火箭
		if_rocket = 1;
	if (if_rocket == 1 && guan == 0)//显示火箭并控制火箭移动
	{
		putimage(position_rocket_x, position_rocket_y1, 72, 48, &img_rocket1, 0, 0);
		putimage(position_rocket_x, position_rocket_y2, 72, 48, &img_rocket1, 0, 0);
		position_rocket_x = position_rocket_x - position_rocket_vx * 20;
		if_rocket = 1;
	}
	if (position_human_x >= position_rocket_x - 50 && position_human_x <= position_rocket_x + 72 && position_human_y >= position_rocket_y1 - 50 && position_human_y <= position_rocket_y2 + 50 && guan == 0)//失败条件
	{
		if_lose = 1;
	}
	if (position_human_x >= 230 && position_human_x <= 490 && jumplimit == 0 && position_human_y >= 350 && guan == 0)//失败条件
	{
		if_ci = 1;
		if_lose = 1;
	}
	if (position_human_x >= 500 && position_human_x <= 525 && position_human_y >= 40 && position_human_y <= 350 && guan == 2)//碰到柱子返回坐标
		position_human_x = 485;
	if (position_human_x >= 525 && position_human_x <= 550 && position_human_y >= 40 && position_human_y <= 350 && guan == 2)//碰到柱子返回坐标
		position_human_x = 560;
	if (brick1 == 1)//判断显示砖块
		putimage(480, 265, 50, 50, &img_brick1, 0, 0);
	if (position_human_x >= position_princess_x - 45 && position_human_x <= position_princess_x + 45 && position_human_y >= position_princess_y - 45 && position_human_y <= position_princess_y + 20 && guan == 2)//胜利条件
		if_victory = 1;

	if (if_ci == 1)//显示刺
	{
		putimage(275, 360, 30, 15, &img_ci, 0, 0);
		putimage(305, 360, 30, 15, &img_ci, 0, 0);
		putimage(335, 360, 30, 15, &img_ci, 0, 0);
		putimage(365, 360, 30, 15, &img_ci, 0, 0);
		putimage(395, 360, 30, 15, &img_ci, 0, 0);
		putimage(425, 360, 30, 15, &img_ci, 0, 0);
		putimage(455, 360, 30, 15, &img_ci, 0, 0);
		putimage(485, 360, 30, 15, &img_ci, 0, 0);
		putimage(270, 237, 260, 120, &img_chaoxiao, 0, 0);

	}
	if (if_lose == 1)
	{
		lose1();
		lose2();

	}

	if (if_victory == 1)
		victory();







}
void left_first()//第一关向左走
{
	if ((GetAsyncKeyState(0x41) & 0x8000))//向左走
	{
		if (if_inputleft == 1)//显示不同的图片
		{
			clearrectangle(position_human_x, position_human_y, position_human_x + 50, position_human_y + 50);//清空矩形区域
			chonghua_first();
			position_human_x = position_human_x - 15;

			if (left_i == 2 && if_lose == 0)//显示不同的图片
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 150, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 150, SRCINVERT);
			}
			if (left_i == 3 && if_lose == 0)//显示不同的图片
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 150, NOTSRCERASE);//循环播放小人向左走的组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 50, 150, SRCINVERT);//循环播放小人向左走的组图
			}
			FlushBatchDraw();
			Sleep(40);
			if (left_i == 3)
				left_i = 1;
			left_i++;
			if_inputleft = 0;
		}
		if (if_inputleft == 0 && if_lose == 0)//向左走停下之后
		{
			putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, NOTSRCERASE);
			putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 50, SRCINVERT);
			if_inputleft = 1;
		}
	}
}
void left_second()//第二关向左走
{
	if ((GetAsyncKeyState(0x41) & 0x8000))//向左走
	{
		if (if_inputleft == 1)
		{
			clearrectangle(position_human_x, position_human_y, position_human_x + 50, position_human_y + 50);
			chonghua_second();
			position_human_x = position_human_x - 15;
			if (left_i == 2 && if_lose == 0)//显示不同的图片
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 150, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 150, SRCINVERT);
			}
			if (left_i == 3 && if_lose == 0)//显示不同的图片
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human1, 50, 150, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 150, SRCINVERT);
			}
			FlushBatchDraw();
			Sleep(40);
			if (left_i == 3)
				left_i = 1;
			left_i++;
			if_inputleft = 0;
		}
		if (if_inputleft == 0 && if_lose == 0)//向左走停下之后
		{
			putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 50, NOTSRCERASE);
			putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, SRCINVERT);
			if_inputleft = 1;
		}
	}
}
void right_first()//第一关向右走
{

	if ((GetAsyncKeyState(0x44) & 0x8000))//向右走
	{

		if (if_inputright == 1)
		{
			clearrectangle(position_human_x, position_human_y, position_human_x + 50, position_human_y + 50);//清空矩形区域	
			chonghua_first();
			if (position_human_x < width - 50)
				position_human_x = position_human_x + 15;



			if (right_i == 2 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 200, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 200, SRCINVERT);
			}
			if (right_i == 3 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 200, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 50, 200, SRCINVERT);//循环播放小人向右走的组图
			}
			FlushBatchDraw();
			Sleep(40);
			if (right_i == 3)
				right_i = 1;
			right_i++;
			if_inputright = 0;
		}
		if (if_inputright == 0 && if_lose == 0)//向右走停下之后
		{
			putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 50, NOTSRCERASE);
			putimage(position_human_x, position_human_y, 50, 50, &img_human, 50, 50, SRCINVERT);
			if_inputright = 1;
		}
	}


}
void right_second()//第二关向右走
{

	if ((GetAsyncKeyState(0x44) & 0x8000))//向右走
	{

		if (if_inputright == 1)
		{
			clearrectangle(position_human_x, position_human_y, position_human_x + 50, position_human_y + 50);//清空矩形区域
			chonghua_second();
			if (position_human_x < width - 50)
				position_human_x = position_human_x + 15;

			if (right_i == 2 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 200, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 200, SRCINVERT);
			}
			if (right_i == 3 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human1, 50, 200, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 200, SRCINVERT);//循环播放小人向右走的组图
			}
			FlushBatchDraw();
			Sleep(40);
			if (right_i == 3)
				right_i = 1;
			right_i++;
			if_inputright = 0;
		}
		if (if_inputright == 0 && if_lose == 0)//向右走停下之后
		{
			putimage(position_human_x, position_human_y, 50, 50, &img_human1, 50, 50, NOTSRCERASE);
			putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 50, SRCINVERT);
			if_inputright = 1;
		}
	}

}
void up1_first()//第一关向上走
{
	if (GetAsyncKeyState(0x57) & 0x8000 && if_lose == 0)
	{
		jumplimit = 8;//跳跃高度限制
		while (jumplimit > 0)
		{
			if ((GetAsyncKeyState(0x44) & 0x8000) && if_lose == 0)//跳起时向右
			{
				position_human_x += 10;
				jumpright = 1;
				jumpleft = 0;
			}

			if ((GetAsyncKeyState(0x41) & 0x8000) && if_lose == 0)//跳起时向左
			{
				position_human_x -= 10;
				jumpleft = 1;
				jumpright = 0;
			}
			if (brick1 == 1 && brick2 == 1 && brick3 == 1 && brick4 == 1 && brick5 == 1)//满足条件显示陷阱
			{
				rocketmove();
				putimage(0, 0, 1000, 600, &img_first, bk_x, 0);
				putimage(rocket1_x, 420, &img_rocket2, NOTSRCERASE);
				putimage(rocket1_x, 420, &img_rocket, SRCINVERT);
				putimage(rocket2_x, 360, &img_rocket4, NOTSRCERASE);
				putimage(rocket2_x, 360, &img_rocket3, SRCINVERT);
				putimage(390, 315, 50, 50, &img_brick, 0, 0);
				putimage(340, 315, 50, 50, &img_brick, 0, 0);
				putimage(290, 315, 50, 50, &img_brick, 0, 0);
				putimage(240, 315, 50, 50, &img_brick, 0, 0);
				putimage(190, 315, 50, 50, &img_brick, 0, 0);
			}



			clearrectangle(position_human_x - 10, position_human_y, position_human_x + 60, position_human_y + 49);//清空画面矩形区域
			chonghua_first();
			position_human_y = position_human_y - jumplimit * jumplimit;//加速上升
			xian();

			if (jumpleft == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 100, NOTSRCERASE);//循环播放上升组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 100, SRCINVERT);//循环播放上升组图
			}
			if (jumpright == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 100, NOTSRCERASE);//循环播放上升组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 50, 100, SRCINVERT);//循环播放上升组图
			}
			FlushBatchDraw();
			Sleep(50);
			jumplimit--;
		}
	}
}
void up2_first()//第一关向上走（不同情况）
{

	if (GetAsyncKeyState(0x57) & 0x8000 && if_lose == 0)
	{
		while (jumplimit > 0)
		{
			if ((GetAsyncKeyState(0x44) & 0x8000) && if_lose == 0)//跳起时向右
			{
				position_human_x += 10;
				jumpright = 1;
				jumpleft = 0;
			}

			if ((GetAsyncKeyState(0x41) & 0x8000) && if_lose == 0)//跳起时向左
			{
				position_human_x -= 10;
				jumpleft = 1;
				jumpright = 0;
			}

			if (brick1 == 1 && brick2 == 1 && brick3 == 1 && brick4 == 1 && brick5 == 1)
			{
				rocketmove();
				putimage(0, 0, 1000, 600, &img_first, bk_x, 0);
				putimage(rocket1_x, 420, &img_rocket2, NOTSRCERASE);
				putimage(rocket1_x, 420, &img_rocket, SRCINVERT);
				putimage(rocket2_x, 360, &img_rocket4, NOTSRCERASE);
				putimage(rocket2_x, 360, &img_rocket3, SRCINVERT);
				putimage(390, 315, 50, 50, &img_brick, 0, 0);
				putimage(340, 315, 50, 50, &img_brick, 0, 0);
				putimage(290, 315, 50, 50, &img_brick, 0, 0);
				putimage(240, 315, 50, 50, &img_brick, 0, 0);
				putimage(190, 315, 50, 50, &img_brick, 0, 0);
			}

			clearrectangle(position_human_x - 10, position_human_y, position_human_x + 60, position_human_y + 49);//清空画面矩形区域
			chonghua_first();

			position_human_y = position_human_y - jumplimit * jumplimit;//加速上升

			xian();

			if (jumpleft == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 100, NOTSRCERASE);//循环播放上升组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 100, SRCINVERT);//循环播放上升组图
			}
			if (jumpright == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 100, NOTSRCERASE);//循环播放上升组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 50, 100, SRCINVERT);//循环播放上升组图
			}
			FlushBatchDraw();
			Sleep(20);
			jumplimit--;
			if ((jumplimit == 0) && (position_human_y > 300))
				i = 1;
			if (jumplimit == 0 && position_human_x >= 180 && position_human_x <= 250 && guan == 2)
			{
				brick1 = 1;
			}
			if (jumplimit == 0 && position_human_x >= 230 && position_human_x <= 300 && guan == 2)
			{
				brick2 = 1;
			}
			if (jumplimit == 0 && position_human_x >= 280 && position_human_x <= 350 && guan == 2)
			{
				brick3 = 1;
			}
			if (jumplimit == 0 && position_human_x >= 330 && position_human_x <= 400 && guan == 2)
			{
				brick4 = 1;
			}
			if (jumplimit == 0 && position_human_x >= 370 && position_human_x <= 450 && guan == 2)
			{
				brick5 = 1;
			}
			if (jumplimit == 0 && position_human_x >= 150 && position_human_x < 175 && position_human_y < 300 && guan == 2)
			{
				brick6 = 1;
			}
			if (position_human_x >= 400 && position_human_y <= 100)
			{
				k = 1;
			}
			if (k == 1)
				putimage(480, 24, &img_yun);
			if ((i == 1) && (guan == 0))
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(brick_x, 280, 50, 50, &img_brick, 0, 0);
				loadimage(&img_go, _T(".\\图片\\go.jpg"));
				loadimage(&img_go2, _T(".\\图片\\go2.jpg"));
				putimage(go_x, 220, 300, 350, &img_go2, 0, 0, NOTSRCERASE);
				putimage(go_x, 220, 300, 350, &img_go, 0, 0, SRCINVERT);
			}
			if (brick1 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(190, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick2 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(240, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick3 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(290, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick4 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(340, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick5 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(390, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick6 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(180, 165, 50, 50, &img_brick, 0, 0);
				putimage(230, 165, 50, 50, &img_brick, 0, 0);
			}
		}
	}
}
void up3_first()//第一关向上走（不同情况）
{

	if (GetAsyncKeyState(0x57) & 0x8000 && if_lose == 0)
	{
		while (jumplimit > 0)
		{
			if ((GetAsyncKeyState(0x44) & 0x8000) && if_lose == 0)//跳起时向右
			{
				position_human_x += 10;
				jumpright = 1;
				jumpleft = 0;
			}

			if ((GetAsyncKeyState(0x41) & 0x8000) && if_lose == 0)//跳起时向左
			{
				position_human_x -= 10;
				jumpleft = 1;
				jumpright = 0;
			}
			clearrectangle(position_human_x - 10, position_human_y, position_human_x + 60, position_human_y + 49);//清空画面矩形区域
			chonghua_first();

			position_human_y = position_human_y - jumplimit * jumplimit;//加速上升

			xian();

			if (jumpleft == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 100, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 100, SRCINVERT);
			}
			if (jumpright == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 100, NOTSRCERASE);//循环播放上升组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 50, 100, SRCINVERT);//循环播放上升组图
			}
			FlushBatchDraw();
			Sleep(20);
			jumplimit--;

		}
	}
}
void up_second()//第二关向上走
{

	if (GetAsyncKeyState(0x57) & 0x8000)
	{
		while (jumplimit > 0)
		{
			if ((GetAsyncKeyState(0x44) & 0x8000))//跳起时向右
			{
				position_human_x += 10;
				jumpright = 1;
				jumpleft = 0;
			}

			if ((GetAsyncKeyState(0x41) & 0x8000))//跳起时向左
			{
				position_human_x -= 10;
				jumpleft = 1;
				jumpright = 0;
			}
			clearrectangle(position_human_x - 10, position_human_y, position_human_x + 60, position_human_y + 49);

			chonghua_second();

			position_human_y = position_human_y - jumplimit * jumplimit;//加速上升


			if (position_human_x > 120 && position_human_x < 215 && position_human_y < 265 && position_human_y > 205 && guan == 0)
				ground = 260;
			if (position_human_x > 230 && position_human_x < 490 && position_human_y < 200 && guan == 0)
				ground = 190;
			if (position_human_x > 495 && position_human_x <= 820 && position_human_y < 120 && guan == 0)
				ground = 110;
			if (position_human_x >= -100 && position_human_x <= 180 && position_human_y < 120 && guan == 1)
				ground = 110;
			if (position_human_x >= 285 && position_human_x <= 560 && guan == 1)
				ground = 260;
			if (position_human_x >= -100 && position_human_x <= 270 && position_human_y <= 300 && guan == 2)
				ground = 260;
			if (position_human_x >= 450 && position_human_x <= 500 && brick1 == 1 && guan == 2 && position_human_y <= 300)
				ground = 215;
			if (position_human_x >= 500 && position_human_x <= 540 && position_human_y < 170 && guan == 2)
				ground = 15;

			if (jumpleft == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 100, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 100, SRCINVERT);
			}
			if (jumpright == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human1, 50, 100, NOTSRCERASE);//循环播放上升组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 100, SRCINVERT);//循环播放上升组图
			}

			FlushBatchDraw();
			Sleep(50);
			jumplimit--;

		}

	}

}
void down2_first()//第一关向下走（不同情况）
{
	if ((position_human_y < ground))//在砖块上时
	{
		downlimit = 1;
		while (position_human_y < ground)//跳起时自动下落
		{
			if ((GetAsyncKeyState(0x44) & 0x8000) && if_lose == 0)//下落时向右
			{

				position_human_x += 10;
				jumpright = 1;
				jumpleft = 0;

			}

			if ((GetAsyncKeyState(0x41) & 0x8000) && if_lose == 0)//下落时向左
			{

				position_human_x -= 10;
				jumpleft = 1;
				jumpright = 0;

			}
			if (brick1 == 1 && brick2 == 1 && brick3 == 1 && brick4 == 1 && brick5 == 1)
			{
				rocketmove();
				putimage(0, 0, 1000, 600, &img_first, bk_x, 0);
				putimage(rocket1_x, 420, &img_rocket2, NOTSRCERASE);
				putimage(rocket1_x, 420, &img_rocket, SRCINVERT);
				putimage(rocket2_x, 360, &img_rocket4, NOTSRCERASE);
				putimage(rocket2_x, 360, &img_rocket3, SRCINVERT);
				putimage(390, 315, 50, 50, &img_brick, 0, 0);
				putimage(340, 315, 50, 50, &img_brick, 0, 0);
				putimage(290, 315, 50, 50, &img_brick, 0, 0);
				putimage(240, 315, 50, 50, &img_brick, 0, 0);
				putimage(190, 315, 50, 50, &img_brick, 0, 0);
			}
			clearrectangle(position_human_x - 10, position_human_y, position_human_x + 60, position_human_y + 60);//清空画面矩形区域
			chonghua_first();

			position_human_y = position_human_y + downlimit * downlimit;//跳起时自动加速下落

			xian();

			if (guan == 2)
			{
				if (position_human_x < 65)
				{
					ground = 420;
				}
				if (position_human_x >= 65 && position_human_x < 170 && position_human_y < 300)
				{
					ground = 270;
				}
				if (position_human_x >= 160 && position_human_x <= 280 && position_human_y < 200)
				{
					ground = 110;
				}
				if (position_human_x >= 400 && position_human_x <= 510 && position_human_y < 300)
				{
					ground = 270;
				}
			}
			if (jumpleft == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 100, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 100, SRCINVERT);
			}
			if (jumpright == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 100, NOTSRCERASE);//循环播放下落组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human, 50, 100, SRCINVERT);
			}
			FlushBatchDraw();//执行未完成的绘制任务
			Sleep(100);
			downlimit++;
		}
		clearrectangle(position_human_x - 10, position_human_y, position_human_x + 60, position_human_y + 60);
		position_human_y = ground;
		putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 50, NOTSRCERASE);
		putimage(position_human_x, position_human_y, 50, 50, &img_human, 50, 50, SRCINVERT);
	}
}
void down_second()//自定义地面，第二关向下走
{
	if ((position_human_y < ground))//在砖块上时
	{
		downlimit_human = 1;
		while (position_human_y < ground)//跳起时自动下落
		{
			if ((GetAsyncKeyState(0x44) & 0x8000))//下落时向右
			{

				position_human_x += 10;
				jumpright = 1;
				jumpleft = 0;

			}

			if ((GetAsyncKeyState(0x41) & 0x8000))//下落时向左
			{

				position_human_x -= 10;
				jumpleft = 1;
				jumpright = 0;

			}

			clearrectangle(position_human_x - 10, position_human_y, position_human_x + 60, position_human_y + 60);
			chonghua_second();
			position_human_y = position_human_y + downlimit_human * downlimit_human;//跳起时自动加速下落


			if (position_human_x > 120 && position_human_x < 215 && position_human_y < 265 && position_human_y > 205 && guan == 0)
				ground = 260;
			if (position_human_x > 230 && position_human_x < 490 && position_human_y < 200 && guan == 0)
				ground = 190;
			if (position_human_x > 495 && position_human_x <= 820 && position_human_y < 120 && guan == 0)
				ground = 110;
			if (position_human_x >= -100 && position_human_x <= 180 && position_human_y < 120 && guan == 1)
				ground = 110;
			if (position_human_x >= 285 && position_human_x <= 560 && guan == 1)
				ground = 260;
			if (position_human_x >= -100 && position_human_x <= 270 && position_human_y <= 300 && guan == 2)
				ground = 260;
			if (position_human_x >= 450 && position_human_x <= 500 && brick1 == 1 && guan == 2 && position_human_y <= 300)
				ground = 215;
			if (position_human_x >= 500 && position_human_x <= 540 && position_human_y < 170 && guan == 2)
				ground = 15;


			if (jumpleft == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 100, NOTSRCERASE);
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 100, SRCINVERT);
			}
			if (jumpright == 1 && if_lose == 0)
			{
				putimage(position_human_x, position_human_y, 50, 50, &img_human1, 50, 100, NOTSRCERASE);//循环播放下落组图
				putimage(position_human_x, position_human_y, 50, 50, &img_human2, 50, 100, SRCINVERT);
			}
			FlushBatchDraw();//执行未完成的绘制任务
			Sleep(100);
			downlimit_human++;
		}
		clearrectangle(position_human_x - 10, position_human_y, position_human_x + 60, position_human_y + 60);
		position_human_y = ground;
	}
}
void updateWithoutInput_first()  // 与用户输入无关的更新
{

}
void updateWithoutInput_second()  // 与用户输入无关的更新
{

}
void updateWithInput_start()  // 与用户输入有关的更新
{
	MOUSEMSG m;
	while (MouseHit())//鼠标交互
	{
		m = GetMouseMsg();
		if (m.x >= 0 && m.x <= 960 && m.y >= 0 && m.y <= 580 && m.uMsg == WM_LBUTTONDOWN && flag == 10)//第一幕
			flag = 11;
		else if (m.x >= 0 && m.x <= 960 && m.y >= 0 && m.y <= 580 && m.uMsg == WM_LBUTTONDOWN && flag == 11)//第二幕
			flag = 12;
		else if (m.x >= 0 && m.x <= 960 && m.y >= 0 && m.y <= 580 && m.uMsg == WM_LBUTTONDOWN && flag == 12)//第三幕
			flag = 13;
		else if (m.x >= 0 && m.x <= 960 && m.y >= 0 && m.y <= 580 && m.uMsg == WM_LBUTTONDOWN && flag == 13)//第四幕
			flag = 0;
		else if (m.x >= 520 && m.x <= 697 && m.y >= 275 && m.y <= 371 && m.uMsg == WM_LBUTTONDOWN && flag == 0)//点击开始，进入关卡
			flag = 1;
		else if (m.x >= 679 && m.x <= 805 && m.y >= 391 && m.y <= 460 && m.uMsg == WM_LBUTTONDOWN && flag == 0)//显示关于界面
			flag = 2;
		else if (m.x >= 558 && m.x <= 680 && m.y >= 428 && m.y <= 480 && m.uMsg == WM_LBUTTONDOWN && flag == 2)//返回开始界面
			flag = 0;
		else if (m.x >= 330 && m.x <= 420 && m.y >= 235 && m.y <= 335 && m.uMsg == WM_LBUTTONDOWN && flag == 1)//进入第一个关卡
			flag = 3;
		else if (m.x >= 10 && m.x <= 50 && m.y >= 10 && m.y <= 50 && m.uMsg == WM_LBUTTONDOWN && flag == 1)//返回开始界面
			flag = 0;
		else if (m.x >= 10 && m.x <= 70 && m.y >= 20 && m.y <= 80 && m.uMsg == WM_LBUTTONDOWN && flag == 3)//返回关卡界面

			flag = 1;

		else if (m.x >= 412 && m.x <= 512 && m.y >= 400 && m.y <= 453 && m.uMsg == WM_LBUTTONDOWN && flag == 0)//进入说明界面

			flag = 8;

		else if (m.x >= 880 && m.x <= 930 && m.y >= 10 && m.y <= 70 && m.uMsg == WM_LBUTTONDOWN && flag == 8)//返回开始界面
			flag = 0;
		else if (m.x >= 360 && m.x <= 460 && m.y >= 284 && m.y <= 340 && m.uMsg == WM_LBUTTONDOWN && flag == 0)//进入作者
			flag = 6;
		else if (m.x >= 884 && m.x <= 930 && m.y >= 493 && m.y <= 540 && m.uMsg == WM_LBUTTONDOWN && flag == 6)//返回开始界面
			flag = 0;
		else if (m.x >= 745 && m.x <= 845 && m.y >= 300 && m.y <= 355 && m.uMsg == WM_LBUTTONDOWN && flag == 0)//进入操作
			flag = 5;
		else if (m.x >= 890 && m.x <= 950 && m.y >= 10 && m.y <= 60 && m.uMsg == WM_LBUTTONDOWN && flag == 5)//返回开始界面
			flag = 0;
		else if (m.x >= 432 && m.x <= 530 && m.y >= 222 && m.y <= 322 && m.uMsg == WM_LBUTTONDOWN && flag == 1)//进入第二关
			flag = 4;
	}
}
void updateWithInput_second()
{
	while (stage == 2)
	{
		putimage(0, 0, 3000, 1000, &img_second, bk_x, 0);
		if (position_human_x >= 440 && position_human_x <= 490 && jumplimit == 0 && guan == 2 && position_human_y > 250 && position_human_y < 350)
			brick1 = 1;
		if (position_human_x >= 150 && position_human_x <= 600 && position_human_y >= 400 && guan == 1)
			if_lose = 1;
		if (position_human_x >= position_guai2_x - 45 && position_human_x <= position_guai2_x + 20 && position_human_y >= position_guai2_y - 40 && position_human_y <= position_guai2_y + 40 && guan == 2)
		{
			putimage(position_guai2_x, position_guai2_y, 50, 50, &img_guai1, 0, 0, NOTSRCERASE);
			putimage(position_guai2_x, position_guai2_y, 50, 50, &img_guai2, 0, 0, SRCINVERT);
			if_lose = 1;
		}
		if (position_human_x >= position_guai1_x - 45 && position_human_x <= position_guai1_x + 40 && position_human_y >= position_guai1_y - 40 && position_human_y <= position_guai1_y + 40 && guan == 1)
		{
			putimage(position_guai1_x, position_guai1_y, 50, 50, &img_guai1, 0, 0, NOTSRCERASE);
			putimage(position_guai1_x, position_guai1_y, 50, 50, &img_guai2, 0, 0, SRCINVERT);
			if_lose = 1;
		}

		if (position_human_x >= 495 && position_human_x <= 650 && position_human_y == 110 && guan == 0)
			if_rocket = 1;
		if (if_rocket == 1 && guan == 0)
		{
			putimage(position_rocket_x, position_rocket_y1, 72, 48, &img_rocket1, 0, 0);
			putimage(position_rocket_x, position_rocket_y2, 72, 48, &img_rocket1, 0, 0);
			position_rocket_x = position_rocket_x - position_rocket_vx;
			if_rocket = 1;
		}
		if (position_human_x >= position_rocket_x - 45 && position_human_x <= position_rocket_x + 72 && position_human_y >= position_rocket_y1 - 50 && position_human_y <= position_rocket_y2 + 50 && guan == 0)
		{
			if_lose = 1;
		}
		if (position_human_x >= 230 && position_human_x <= 490 && jumplimit == 0 && position_human_y >= 350 && guan == 0)
		{
			if_ci = 1;
			if_lose = 1;
		}
		if (position_human_x >= 500 && position_human_x <= 525 && position_human_y >= 40 && position_human_y <= 350 && guan == 2)
			position_human_x = 485;
		if (position_human_x >= 525 && position_human_x <= 550 && position_human_y >= 40 && position_human_y <= 350 && guan == 2)
			position_human_x = 560;
		if (brick1 == 1)
			putimage(480, 265, 50, 50, &img_brick1, 0, 0);
		if (position_human_x >= position_princess_x - 45 && position_human_x <= position_princess_x + 45 && position_human_y >= position_princess_y - 45 && position_human_y <= position_princess_y + 20 && guan == 2)
			if_victory = 1;
		if (if_ci == 1)
		{
			putimage(275, 360, 30, 15, &img_ci, 0, 0);
			putimage(305, 360, 30, 15, &img_ci, 0, 0);
			putimage(335, 360, 30, 15, &img_ci, 0, 0);
			putimage(365, 360, 30, 15, &img_ci, 0, 0);
			putimage(395, 360, 30, 15, &img_ci, 0, 0);
			putimage(425, 360, 30, 15, &img_ci, 0, 0);
			putimage(455, 360, 30, 15, &img_ci, 0, 0);
			putimage(485, 360, 30, 15, &img_ci, 0, 0);
			putimage(270, 237, 260, 120, &img_chaoxiao, 0, 0);

		}
		if (if_lose == 1)
		{
			lose1();
			lose2();

		}
		if (if_victory == 1)
			victory();
		if (if_lose == 0)
		{
			BeginBatchDraw();
			putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 50, NOTSRCERASE);
			putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, SRCINVERT);
			FlushBatchDraw();
		}

		if (_kbhit())
		{
			input = _getch();
			if (if_lose == 1)
			{
				lose1();
				lose2();
				if (input == 'q')
					startup_second();//复活
			} 
			if (guan == 0)
			{


				if (position_human_x > 120 && position_human_x < 215 && position_human_y > 350 && guan == 0)
				{
					jumplimit = 5;
					ground = 420;
					left_second();
					right_second();
					up_second();
					down_second();
				}
				if (position_human_x > 230 && position_human_x < 490 && position_human_y > 350 && guan == 0)
				{
					jumplimit = 5;
					ground = 420;
					left_second();
					right_second();
					up_second();
					down_second();
				}
				else if (position_human_x > 120 && position_human_x < 215 && position_human_y > 205 && position_human_y < 265 && guan == 0)
				{
					jumplimit = 8;
					ground = 260;
					left_second();
					right_second();
					up_second();
					down_second();
				}
				else if (position_human_x > 230 && position_human_x < 490 && position_human_y < 200 && guan == 0)
				{
					jumplimit = 8;
					ground = 190;
					left_second();
					right_second();
					up_second();
					down_second();
				}
				else if (position_human_x > 495 && position_human_x <= 820 && position_human_y < 120 && guan == 0)
				{
					jumplimit = 8;
					ground = 110;
					left_second();
					right_second();
					up_second();
					down_second();
				}
				else
				{
					jumplimit = 8;
					ground = 420;
					left_second();
					right_second();
					up_second();
					down_second();
				}
			}
			if ((position_human_x >= 700) && (bk_x >= 0))//满足条件进入第二关下一幕
			{
				while (bk_x <= 620)
				{
					bk_x += 15;//显示背景坐标向右移动
					position_human_x -= 15;
					BeginBatchDraw();
					putimage(0, 0, 1000, 1000, &img_second, bk_x, 0);
					putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 50, NOTSRCERASE);//小人图片
					putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, SRCINVERT);//小人图片
					FlushBatchDraw();
					Sleep(50);
					guan = 1;

				}

			}
			if (guan == 1)
			{
				if (position_human_x >= -100 && position_human_x <= 180 && position_human_y < 120 && guan == 1)
				{
					jumplimit = 8;
					ground = 110;

					left_second();
					right_second();
					up_second();
					down_second();


				}
				else if (position_human_x >= 285 && position_human_x <= 560 && guan == 1)
				{
					jumplimit = 8;
					ground = 260;
					left_second();
					right_second();
					up_second();
					down_second();


				}
				else
				{
					jumplimit = 8;
					ground = 420;
					left_second();
					right_second();
					up_second();
					down_second();
				}
				if (position_human_x >= 600 && bk_x >= 620)
				{
					while (bk_x <= 900)
					{
						bk_x += 15;
						position_human_x -= 15;
						BeginBatchDraw();
						putimage(0, 0, 1000, 1000, &img_second, bk_x, 0);
						putimage(position_human_x, position_human_y, 50, 50, &img_human1, 0, 50, NOTSRCERASE);//小人图片
						putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, SRCINVERT);//小人图片
						FlushBatchDraw();
						Sleep(50);
						guan = 2;
					}

				}
			}
			if (guan == 2)
			{
				if (position_human_x >= 450 && position_human_x <= 500 && brick1 == 1 && position_human_y <= 300)
				{
					jumplimit = 8;
					ground = 215;

					left_second();
					right_second();
					up_second();
					down_second();

				}
				else if (position_human_x >= 440 && position_human_x <= 490 && position_human_y >= 340)
				{
					jumplimit = 6;
					ground = 420;

					left_second();
					right_second();
					up_second();
					down_second();

				}
				else if (position_human_x >= 500 && position_human_x <= 550 && position_human_y > 350)
				{
					jumplimit = 5;
					ground = 420;

					left_second();
					right_second();
					up_second();
					down_second();

				}
				else if (position_human_x >= 500 && position_human_x <= 540 && position_human_y < 170)
				{
					jumplimit = 8;
					ground = 15;

					left_second();
					right_second();
					up_second();
					down_second();

				}

				else if (position_human_x >= -100 && position_human_x <= 270 && position_human_y <= 300)
				{
					jumplimit = 8;
					ground = 260;

					left_second();
					right_second();
					up_second();
					down_second();

				}
				else
				{
					jumplimit = 8;
					ground = 420;
					left_second();
					right_second();
					up_second();
					down_second();
				}

			}


		}
	}
}
void updateWithInput_first()
{

	while (1)
	{

		loadimage(&img_first, _T(".\\图片\\first.jpg"));
		putimage(0, 0, 3000, 1000, &img_first, bk_x, 0);
		if (position_human_x > 800 && guan == 2)
		{
			if_victory = 1;
		}
		if (if_victory == 1)
			victory();
		loadimage(&img_rocket, _T(".\\图片\\rocket.jpg"));
		loadimage(&img_rocket2, _T(".\\图片\\rocket2.jpg"));
		loadimage(&img_rocket3, _T(".\\图片\\rocket3.jpg"));
		loadimage(&img_rocket4, _T(".\\图片\\rocket4.jpg"));
		putimage(rocket1_x, 420, &img_rocket2, NOTSRCERASE);
		putimage(rocket1_x, 420, &img_rocket, SRCINVERT);
		putimage(rocket2_x, 360, &img_rocket4, NOTSRCERASE);
		putimage(rocket2_x, 360, &img_rocket3, SRCINVERT);
		putimage(480, rocketup_y, &img_rocketup2, NOTSRCERASE);
		putimage(480, rocketup_y, &img_rocketup, SRCINVERT);
		if (k == 1)
		{
			putimage(480, 24, &img_yun);


			if_lose = 1;
		}
		if (position_human_x >= 400 && position_human_x <= 510 && position_human_y < 300 && guan == 2)//跳到第二个大烟囱上
		{
			rocketup();
		}
		if (guan == 1 && j == 0)//第二部分显示钥匙
		{
			putimage(270, 280, &img_yaoshi);
		}
		if (ci_ground_show == 1)//当碰到草地时显示陷阱
		{
			putimage(ci_ground_x, 445, &img_ci_ground);


			if_lose = 1;


		}
		if (j == 1)//当碰到钥匙时显示陷阱
		{
			putimage(400, 175, &img_ci_left);
			putimage(180, 175, &img_ci_right);
		}
		if (guan == 2)//第三个部分，在两个大烟囱之间显示砖块
		{
			if (brick1 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(190, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick2 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(240, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick3 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(290, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick4 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(340, 315, 50, 50, &img_brick, 0, 0);
			}
			if (brick5 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(390, 315, 50, 50, &img_brick, 0, 0);

			}
			if (brick6 == 1)
			{
				loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
				putimage(180, 165, 50, 50, &img_brick, 0, 0);
				putimage(230, 165, 50, 50, &img_brick, 0, 0);
			}
		}
		if (i == 1 && guan == 0)//第一部分显示陷阱
		{
			loadimage(&img_brick, _T(".\\图片\\brick.jpg"));
			putimage(brick_x, 280, 50, 50, &img_brick, 0, 0);
			loadimage(&img_go, _T(".\\图片\\go.jpg"));
			loadimage(&img_go2, _T(".\\图片\\go2.jpg"));
			putimage(go_x, 220, 300, 350, &img_go2, 0, 0, NOTSRCERASE);
			putimage(go_x, 220, 300, 350, &img_go, 0, 0, SRCINVERT);
		}




		if (brick1 == 1 && brick2 == 1 && brick3 == 1 && brick4 == 1 && brick5 == 1)//第三部分砖块都出现了，显示陷阱
		{
			rocketmove();
		}
		if (position_human_y == 600 && guan == 0)
		{


			if_lose = 1;

		}
		if (j == 1 && (position_human_x < 220 || position_human_x>350) && guan == 1)
		{
			if_lose = 1;
		}
		if (fabs(rocket1_x - position_human_x) < 10 || fabs(rocket2_x - position_human_x) < 10 && guan == 2)
		{
			if_lose = 1;
		}
		if (fabs(position_human_x - 480) < 10 && fabs(position_human_y - rocketup_y) < 20 && guan == 2)
		{


			if_lose = 1;
		}
		if (if_lose == 0)
		{
			BeginBatchDraw();
			putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, NOTSRCERASE);//小人图片
			putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 50, SRCINVERT);//小人图片
			FlushBatchDraw();
		}
		if (if_lose == 1)
		{
			lose1();
			lose2();

		}



		if (_kbhit())
		{
			input = _getch();//检测输入
			{
				if (if_lose == 1)
				{
					lose1();
					lose2();

					if (input == 'q')
						startup_first();
				}
				if (if_victory == 1)
				{
					victory();


				}

				if ((guan == 0))//第一部分
				{
					left_first();
					right_first();

					if (position_human_x <= 160)
					{
						ground = 420;
						left_first();
						right_first();
						up1_first();
						down2_first();
					}
					if (position_human_x >= 400 && position_human_y <= 100)
					{
						k = 1;
					}
					if (position_human_x > 160 && position_human_x < 250 && position_human_y < 300 && i == 1)
					{
						ground = 230;
						jumplimit = 7;
						left_first();
						right_first();

						up2_first();
						down2_first();
					}

					if (position_human_x > 160 && position_human_x < 270 && position_human_y>300)//在砖块底下
					{
						jumplimit = 6;
						ground = 420;
						left_first();
						right_first();
						up2_first();
						down2_first();
					}

					if ((position_human_x >= 270 && position_human_x < 465 && position_human_y > 300) && (i == 1))//出现了砖块，和第一张图片后
					{
						jumplimit = 6;
						ground = 420;
						left_first();
						right_first();
						up3_first();
						down2_first();
					}
					if (position_human_x >= 270 && position_human_x < 465 && i == 0)
					{
						ground = 420;
						left_first();
						right_first();
						up1_first();
						down2_first();
					}
					if (position_human_x > 180 && position_human_x < 580 && position_human_y < 300)//跳到图片上
					{
						ground = 170;
						jumplimit = 7;
						left_first();
						right_first();
						up2_first();
						down2_first();
					}
					if (position_human_x >= 465 && position_human_x < 600 && position_human_y < 650)//掉下去之后
					{
						ground = 600;
						left_first();
						right_first();
						up1_first();
						down2_first();
					}
					if (position_human_x > 600)
					{
						ground = 420;
						left_first();
						right_first();
						up1_first();
						down2_first();
					}
					if (position_human_x <= 160)
					{
						ground = 420;
						left_first();
						right_first();
						up1_first();
						down2_first();
					}
				}
				if ((position_human_x >= 650) && (bk_x >= 0))//跳到对面后画面移动
				{
					while (bk_x <= 620)
					{
						bk_x += 15;
						position_human_x -= 15;
						brick_x -= 15;
						go_x -= 15;
						BeginBatchDraw();
						putimage(0, 0, 1000, 1000, &img_first, bk_x, 0);
						putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, NOTSRCERASE);//小人图片
						putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 50, SRCINVERT);//小人图片
						if (i == 1)
						{
							putimage(brick_x, 280, 50, 50, &img_brick, 0, 0);
						}
						FlushBatchDraw();
						Sleep(50);
						guan = 1;

					}
				}

				if (guan == 1)//第二个部分
				{
					left_first();
					if ((position_human_x <= 510) && (position_human_y > 300))
					{
						ground = 420;
						if (position_human_x > 125 && position_human_x < 426)//在第一层砖块下
						{
							jumplimit = 4.5;
							left_first();
							right_first();
							up2_first();
							down2_first();
						}
						else//不在第一层砖块下
						{
							left_first();
							right_first();
							if (position_human_x > 510)
								position_human_x = 510;
							up1_first();
							down2_first();
						}
					}
					if (position_human_x > 125 && position_human_x < 426 && position_human_y <= 300 && position_human_y > 190)//在第一层砖块上
					{
						ground = 280;

						if (position_human_x >= 180 && position_human_x <= 370)//在第一层砖块上，第二层砖块下
						{
							jumplimit = 4.5;
							up2_first();
						}
						else//在第一层砖块上，不在第二层砖块下
						{
							up1_first();
						}

						down2_first();
						left_first();
						right_first();
					}

					if ((position_human_x <= 125 || (position_human_x >= 426 && position_human_x <= 510)) && position_human_y < 300)//从第一层砖块上到地面
					{
						ground = 420;
						up1_first();
						down2_first();
						left_first();
						right_first();
					}
					if (position_human_x >= 200 && position_human_x <= 350 && position_human_y < 190)//在第二层砖块上
					{
						ground = 140;
						left_first();
						right_first();
						up1_first();
						down2_first();

					}
					if ((position_human_x > 125 && position_human_x < 200) || (position_human_x > 350 && position_human_x < 426) && position_human_y < 190)//从第二层砖块上到第一层砖块
					{
						ground = 270;
						right_first();
						left_first();
						up1_first();
						down2_first();

					}
					if (position_human_x > 530 && position_human_x < 650 && position_human_y < 400)//跳到第一个大烟囱上
					{
						ground = 270;
						right_first();
						left_first();
						up1_first();
						down2_first();
					}
					if (position_human_x > 100 && position_human_x < 250 && position_human_y > 360)//碰到草丛死亡
					{
						ci_ground_show = 1;
					}
					if (position_human_x > 210 && position_human_x < 300 && position_human_y == 280)//拿到钥匙死亡
					{
						j = 1;
					}
					if (position_human_y < 300)
					{
						left_first();
						right_first();
					}

					if ((position_human_x >= 600) && (bk_x >= 620))//第三部分，画面移动

					{

						while (bk_x <= 1100)
						{
							bk_x += 15;
							position_human_x -= 15;
							BeginBatchDraw();
							putimage(0, 0, 1000, 1000, &img_first, bk_x, 0);
							putimage(position_human_x, position_human_y, 50, 50, &img_human2, 0, 50, NOTSRCERASE);//小人图片
							putimage(position_human_x, position_human_y, 50, 50, &img_human, 0, 50, SRCINVERT);//小人图片
							FlushBatchDraw();
							Sleep(50);
						}
						guan = 2;
					}
				}
				if (guan == 2)
				{
					if (position_human_x < 65)//在第一个大烟囱之前
					{
						ground = 420;
						right_first();
						left_first();
						up1_first();
						down2_first();
					}
					if (position_human_x >= 60 && position_human_x < 150 && position_human_y < 300)//跳到第一个大烟囱
					{
						ground = 270;
						right_first();
						left_first();
						up1_first();
						down2_first();
					}
					if (position_human_x >= 150 && position_human_x < 175 && position_human_y < 300)//到特定区域跳起显示砖块
					{
						ground = 270;
						jumplimit = 5;
						right_first();
						left_first();
						up2_first();
						down2_first();
					}
					if (position_human_x >= 175 && position_human_x <= 400 && position_human_y > 200)//在地面上且在两个大烟囱之间
					{
						jumplimit = 5;
						ground = 420;
						right_first();
						left_first();
						if (position_human_x > 175 && position_human_x < 400)
							up2_first();
						down2_first();
						if (position_human_x < 175)
							position_human_x = 175;
						if (position_human_x > 400)
							position_human_x = 400;
					}
					if (position_human_x >= 160 && position_human_x < 400 && brick6 != 1 && position_human_y < 230)
					{
						jumplimit = 7;
						ground = 420;
						up2_first();
						down2_first();

					}
					if ((position_human_x >= 160 && position_human_x <= 280 && position_human_y < 200) && (brick6 == 1))//跳到砖块上
					{
						ground = 110;
						right_first();
						left_first();
						up1_first();
						down2_first();
					}
					if (position_human_x >= 280 && position_human_x < 430)// && position_human_y>115 && position_human_y < 300)//离开砖块
					{
						ground = 420;
						down2_first();
					}

					if (position_human_x >= 400 && position_human_x <= 510 && position_human_y < 300)//跳到第二个大烟囱上
					{
						ground = 270;
						right_first();
						left_first();
						up1_first();
						down2_first();

					}
					if (position_human_x > 510)//离开第二个大烟囱到地面
					{
						ground = 420;
						right_first();
						left_first();
						up1_first();
						down2_first();
					}

				}
			}

		}
	}
}
int main()
{
	startup_all();  // 数据初始化
	while (1) //  游戏循环执行
	{
		if (stage == 0)//在游戏开始时进入开始界面
		{
			show_start();  // 显示画面
			updateWithoutInput_first();  // 与用户输入无关的更新
			updateWithInput_start();  // 与用户输入有关的更新
		}
		else if (stage == 1)//进入第一关
		{
			startup_first();
			show_first();
			updateWithoutInput_first();
			updateWithInput_first();
		}
		else if (stage == 2)//进入第二关
		{
			startup_second();
			show_second();
			updateWithoutInput_second();
			updateWithInput_second();
		}

	}
	_getch();
	closegraph();
	return 0;
}
