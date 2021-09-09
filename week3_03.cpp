#include <bangtal>
using namespace bangtal;

/*람다 기능으로 대체
bool door1_mouseCallback(ObjectPtr object, int x, int y, MouseAction action)
{
	endGame();
	return true;
}*/

int main()
{
	//장면 생성하기
	auto scene1 = Scene::create("room1", "images/배경-1.png"); //scnePtr
	auto scene2 = Scene::create("room2", "images/배경-2.png");

	//문 생성하기
	auto door1 = Object::create("images/문-오른쪽-닫힘.png", scene1, 800, 270, true);
	auto door2 = Object::create("images/문-왼쪽-열림.png", scene2, 320, 270, true);
	auto door3 = Object::create("images/문-오른쪽-닫힘.png", scene2, 900, 270, true);

	//문을 클릭하면 이동한다
	//door1->setOnMouseCallback(door1_mouseCallback); 람다 함수로 대체 (이름 없는 함수를 만들어 assign)
	door1->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
		scene2->enter();
		return true;
		});
	door3->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action) -> bool {
		endGame();
		return true;
		});


	//게임 시작
	startGame(scene1); //start from 'scene1'
	return 0;
}