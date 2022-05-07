//Range for 
//For each
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class UIComponent
{
protected:
	string name;
public:
	UIComponent(string name) : name(name) {}
	virtual void Show() = 0;
	virtual void Hide() = 0;
};
class Button : public UIComponent
{
public:
	using UIComponent::UIComponent;

	void Show()
	{
	}
	void Hide()
	{
	}
};
class Edit : public UIComponent
{
public:
	using UIComponent::UIComponent;

	void Show()
	{
	}
	void Hide()
	{
	}
};
class Combo : public UIComponent
{
public:
	using UIComponent::UIComponent;

	void Show()
	{
	}
	void Hide()
	{
	}
};
class ListBox : public UIComponent
{
public:
	using UIComponent::UIComponent;

	void Show()
	{
	}
	void Hide()
	{
	}
};
class UIContainer : public UIComponent
{
public:
	using UIComponent::UIComponent;
private:
	vector<UIComponent*> components;
public:
	void add(UIComponent *component)
	{
		components.push_back(component);
	}
	void Show()
	{
		for (UIComponent *component : components)
		{
			component->Show();
		}
	}
	void Hide()
	{
		for (UIComponent *component : components)
		{
			component->Hide();
		}
	}
};
class Window : public UIContainer
{
public:
	using UIContainer::UIContainer;
	void Show()
	{
		cout << name << " - Show" << endl;
		UIContainer::Show();
	}
	void Hide()
	{
		cout << name << " - Hide" << endl;
		UIContainer::Hide();
	}
};
class Panel : public UIContainer
{
public:
	using UIContainer::UIContainer;
	void Show()
	{
		cout << name << " - Show" << endl;
		UIContainer::Show();
	}
	void Hide()
	{
		cout << name << " - Hide" << endl;
		UIContainer::Hide();
	}
};

void main()
{
	Window w1("w1");

	Button b1("b1");
	Edit e1("e1");

	Combo c1("c1");
	ListBox c2("c2");

	Panel p1("p1");
	p1.add(&c1);
	p1.add(&c2);

	w1.add(&b1);
	w1.add(&e1);
	w1.add(&p1);

	w1.Show(); // w1-Show, b1-Show, e1-Show, p1-Show, c1-Show, c2-Show
	w1.Hide();
}

