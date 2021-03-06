#include "stdafx.h"
#include "Player.h"
#include "Monster.h"
#include "Dungeon.h"

Dungeon::Dungeon(Player *pPlayer)
{
	cout << "Dungeon 생성자" << endl;
	system("pause");

	Init();

	this->pPlayer = pPlayer;

	battleLoop = BATTLE_STATE::AGAIN; // 초기 state가 던전 계속 탐험.
}

Dungeon::~Dungeon()
{
	cout << "Dungeon 소멸자" << endl;
	system("pause");

	Release();
}

void Dungeon::Init(void)
{
	pPlayer = nullptr;
	pMonster = nullptr;
}

bool Dungeon::Progress(void)
{
	int sel = 0;

	while (TRUE)
	{
		system("cls");
		pPlayer->showStatus();
		cout << "1. 초급, 2. 중급, 3. 고급, 4. 저장, 5. 불러오기, 6. 종료" << endl;
		cout << "입력: ";
		cin >> sel;

		switch (sel)
		{
		case 1:
			pMonster = new Monster("슬라임", 1, 30, 10);
			break;
		case 2:
			pMonster = new Monster("골렘", 3, 200, 70);
			break;
		case 3:
			pMonster = new Monster("엘드리치", 5, 500, 120);
			break;

		case 4:
			saveData();
			continue;
		case 5:
			loadData();
			continue;
		case 6:
			cout << "게임을 종료합니다." << endl << endl;
			return TRUE;
		}

		if (pMonster == nullptr)
		{
			cout << "오류, 메모리 동적 할당 pMonster Dungeon::Progress()" << endl;
			system("pause");
			continue;
		}

		goIntoTheDungeon();

		switch (battleLoop) {
		case BATTLE_STATE::HUNT:
			getDungeonReward();
			break;
		case BATTLE_STATE::RUN:
			pPlayer->setGold(pPlayer->getGold() >> 1);
			break;
		case BATTLE_STATE::DIE:
			pPlayer->setExp(0);
			break;
		}

		SAFE_DELETE(pMonster); // 전투가 끝나면 몬스터 메모리 해제
							   // Release 함수를 쓰는 것과 용도를 어떻게 비교해야할까나...

		return FALSE; // 던전에서 게임 종료할 수 있도록...
	}
}

void Dungeon::Release(void)
{
	SAFE_DELETE(pMonster);
}

void Dungeon::goIntoTheDungeon(void)
{
	int sel = 0;

	battleLoop = BATTLE_STATE::AGAIN;
	while (battleLoop == BATTLE_STATE::AGAIN)
	{
		system("cls");
		pPlayer->showStatus();
		pMonster->showStatus();
		cout << "1. 공격, 2. 도망" << endl;
		cout << "입력: ";
		cin >> sel;

		switch (sel)
		{
		case 1:
			battleLoop = attackMonster(FALSE); // 솔직히 멤버 변수 접근이라...
										  // MainGame을 벗어나지 않는 한, 어차피 존재해야하는 변수임.
			break;
		case 2:
			battleLoop = tryRunAway();
			if (battleLoop != BATTLE_STATE::RUN) {
				battleLoop = attackMonster(TRUE);
			}
			break;

		default:
			cout << "잘못된 선택입니다." << endl << endl;
			system("pause");
			continue;
		}
	}
}

BATTLE_STATE Dungeon::attackMonster(bool isMonsterAtt)
{
	system("cls");

	if (isMonsterAtt != TRUE)
	{
		pMonster->getDamaged(pPlayer->getAttackDamage());
	}
	pPlayer->getDamaged(pMonster->getAttackDamage());

	if (pPlayer->getHp() <= 0)
	{
		pPlayer->setHp(0);

		if (pMonster->getHp() <= 0)
		{
			pMonster->setHp(0);
		}

		pPlayer->showStatus();
		pMonster->showStatus();

		if (pMonster->getHp() <= 0)
		{
			cout << "아깝게도..." << endl;
		}

		cout << "[사냥 실패] 플레이어가 죽었습니다." << endl << endl;
		system("pause");

		return BATTLE_STATE::DIE;
	}
	else if (pMonster->getHp() <= 0)
	{
		pMonster->setHp(0);

		pPlayer->showStatus();
		pMonster->showStatus();

		cout << "[사냥 성공] 몬스터가 죽었습니다." << endl << endl;
		system("pause");

		return BATTLE_STATE::HUNT;
	}

	return BATTLE_STATE::AGAIN;
}

BATTLE_STATE Dungeon::tryRunAway(void)
{
	int probability = rand() % 4;

	if (probability == 0)
	{
		cout << "[도망 성공] 그러나, 약간의 골드를 잃어버렸습니다." << endl << endl;
		system("pause");

		return BATTLE_STATE::RUN;
	}
	else
	{
		cout << "[도망 실패] 몬스터가 강해지고, 반격을 합니다." << endl << endl;
		pMonster->setAttackDamage(pMonster->getAttackDamage() + 5); // 증가량 밸런싱

		system("pause");

		return BATTLE_STATE::AGAIN;
	}
}

void Dungeon::getDungeonReward(void)
{
	// 경험치와 골드 획득 로직

	pPlayer->getReward(pMonster->getExp(), pMonster->getGold());

}

void Dungeon::saveData(void)
{
	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./hello.txt", "wb");

	if (pPlayer == nullptr) {

		cout << "오류, 플레이어가 없습니다. saveData()" << endl;
		system("pause");
		return;
	}

	if (err == 0)
	{
		cout << "데이터를 저장 합니다." << endl << endl;

		

		fwrite(pPlayer, sizeof(Player), 1, fp);

		fclose(fp);
		system("pause");
	}
	else
	{

		cout << "데이터 저장에 실패했습니다." << endl << endl;

		system("pause");
	}
}

bool Dungeon::loadData(void)
{
	FILE *fp = nullptr;
	errno_t err = fopen_s(&fp, "./hello.txt", "rb");

	if (err == 0)
	{
		cout << "데이터를 불러옵니다." << endl << endl;

		SAFE_DELETE(pPlayer);

		pPlayer = new Player(); // 쓰레기 값
		if (pPlayer == nullptr)
		{
			cout << "오류, 메모리 동적 할당 MainGame::loadData()" << endl << endl;

			cout << "게임을 새로 시작합니다." << endl << endl;

			system("pause");
			return FALSE;
		}

		fread(pPlayer, sizeof(Player), 1, fp); // Player 객체에 값 넣어줌.

		fclose(fp);
		system("pause");

		return TRUE;
	}
	else
	{

		cout << "데이터 불러오기가 실패했습니다." << endl << endl;
		system("pause");

		return FALSE;
	}
}

void Dungeon::setPPlayer(Player *pPlayer)
{
	this->pPlayer = pPlayer;
}
