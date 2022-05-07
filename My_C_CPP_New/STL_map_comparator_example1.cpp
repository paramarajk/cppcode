#include <iostream>
#include <map>
#include <string>

using namespace std;

class user {
	int m_id;
	string m_name;
public:
	user(string name, int id) : m_name(name), m_id(id) {
		//cout << "user ctor called" << endl;
	}
	~user() {
		//cout << "user dtor called" << endl;
	}

	string getname()const {
		return m_name;
	}

	int getid() {
		return m_id;
	}

	bool operator<(const user& obj) const {
		if (this->m_id < obj.m_id) {
			return true;
		}
		else {
			return false;
		}
	}
};

void example1() {
	map<user, int> m_userInfo;

	m_userInfo.insert(make_pair<user, int>(user("Mr.X", 3), 100));
	m_userInfo.insert(make_pair<user, int>(user("Mr.X", 1), 130));
	m_userInfo.insert(make_pair<user, int>(user("Mr.Z", 1), 300));

	map<user, int>::iterator it = m_userInfo.begin();
	for (; it != m_userInfo.end(); it++) {
		cout << it->first.getname() << ":::" << it->second << endl;
	}
}

struct UserNameComparator {
	bool operator()(const user& left, const user& right) {
		if (left.getname() > right.getname()) {
			return true;
		}
		else {
			return false;
		}
	}
};

void example2() {
	map<user, int, UserNameComparator> m_userInfo;
	m_userInfo.insert(make_pair<user, int>(user("Mr.X", 3), 100));
	m_userInfo.insert(make_pair<user, int>(user("Mr.X", 1), 130));
	m_userInfo.insert(make_pair<user, int>(user("Mr.Z", 2), 300));

	map<user, int, UserNameComparator>::iterator it = m_userInfo.begin();
	for (; it != m_userInfo.end(); it++) {
		cout << it->first.getname() << ":::" << it->second << endl;
	}
}

int main() {
	cout << "Comparing using user id" << endl;
	example1();
	cout << "Comparing using user name" << endl;
	example2();
	return 0;
}
