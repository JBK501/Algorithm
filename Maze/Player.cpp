#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);

	// 목적지 도착하기 전에는 계속 실행
	Pos dest = board->GetExitPos();

	Pos front[4] =
	{
		Pos {-1, 0},		// UP
		Pos {0, -1},		// LEFT
		Pos {1, 0},			// DOWN
		Pos {0, 1}			// RIGHT
	};
	
	while (pos != dest)
	{
		// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인.
		int32 newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전.
			_dir = newDir;
			// 앞으로 한 보 전진.
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인.
		else if (CanGo(pos + front[_dir]))
		{
			// 앞으로 한 보 전진
			pos += front[_dir];
			_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전.

			_dir = (_dir + 1) % DIR_COUNT;
			/*switch (_dir)
			{
				case DIR_UP:
					_dir = DIR_LEFT;
					break;
				case DIR_LEFT:
					_dir = DIR_DOWN;
					break;
				case DIR_DOWN:
					_dir = DIR_RIGHT;
					break;
				case DIR_RIGHT:
					_dir = DIR_UP;
					break;
				default:
					break;
			}*/
		}

	}

	// 불필요한 이동 거르기
	stack<Pos> s;

	// 목적지 이전까지 반복한다.
	for (int i = 0; i < _path.size() - 1; i++)
	{
		// 스택의 최상위 원소가 다음으로 가야하는 길과 일치하면(불 필요한 길을 이동하여 되돌아 가고 있는 경우임)
		if (s.empty() == false && s.top() == _path[i + 1])
		{
			s.pop();	// 해당 위치를 삭제한다. (그곳으로 가는 경로를 없앤다)
		}
		else  // 정상적인 길일 때 
		{
			s.push(_path[i]);	// 스택에 경로를 추가한다.
		}
	}

	// 목적지 도착
	if (_path.empty() == false)
	{
		s.push(_path.back());
	}

	vector<Pos> path;
	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}

	// 스택 특성상 경로가 역순으로 저장되어 있을 것이기 때문에 뒤집어준다.
	std::reverse(path.begin(), path.end());

	_path = path;
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
		return;

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}
}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);


	return tileType == TileType::EMPTY;
}
