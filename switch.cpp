#include <iostream>
int main() {
	int user_input;
    std::cout << "저의 정보를 표시해줍니다" << std::endl;
    std::cout << "1. 이름 " << std::endl;
    std::cout << "2. 나이 " << std::endl;
    std::cout << "3. 성별 " << std::endl;
    std::cin >> user_input;

    switch (user_input) {
    case 1:
        std::cout << "Psi ! " << std::endl;
        break;

    case 2:
        std::cout << "99 살" << std::endl;
        break;

    case 3:
        std::cout << "남자" << std::endl;
        break;

    default:
        std::cout << "궁금한게 없군요~" << std::endl;
        break;
    }
    return 0;
}
