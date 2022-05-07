//Powerpoint document - PPTX (accepts shape objects)

//Shape object
//image object
//Animation object
//Text object
//video object
//audio object
//Requirement
/*covert it to PDF:shape, image, text
Flash: shape, image, text, animation, video, audio

create a new app a
create fictious objects and put them in array, 

apply pdf conversion
apply flash conversion
apply video conversion 
apply all these 3 conversions */
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <map>
#include <unordered_map>

#include <set>
#include <unordered_set>

using namespace std;

class Shape;
class Image;
class Animation;
class Audio;
class Converter
{
public:
	virtual void Convert(Shape *shape) { }
	virtual void Convert(Image *image) { }
	virtual void Convert(Animation *animation) {  }
};

class Converter2 : public Converter
{
public:
	virtual void Convert(Audio *audio) {  }
};

class Item
{
protected:
	string name;
	Item(string name) : name(name) { }
public:
	void DisplayName() { cout << name << endl; }

	virtual void Convert(Converter *converter) = 0;
};

//class newItem :public Item {
//public:
//	newItem(string name) :Item(name){}
//	virtual void Convert(Converter2 *converter) {}
//};

class Audio : public Item
{
private:
	int vol;
public:
	Audio() : Item("Audio"), vol(500) { }

	int getVolume() const { return vol; }

	void Convert(Converter2 *converter)
	{
		converter->Convert(this);
	}
};

class Shape : public Item
{
private:
	int x1;
public:
	Shape() : Item("Shape"), x1(10) { }

	int getX1() const { return x1; }

	void Convert(Converter *converter)
	{
		converter->Convert(this);
	}
};

class Image : public Item
{
	double opacity;
public:
	Image() : Item("Image"), opacity(0.5) { }

	int getOpacity() const { return opacity; }

	void Convert(Converter *converter)
	{
		converter->Convert(this);
	}
};

class Animation : public Item
{
	int time;
public:
	Animation() : Item("Animation"), time(100) { }

	int getTime() const { return time; }

	void Convert(Converter *converter)
	{
		converter->Convert(this);
	}
};



class PowerPointSlide
{
private:
	vector<unique_ptr<Item>> items;
public:
	void Create()
	{
		items.push_back(unique_ptr<Item>(new Shape));
		items.push_back(unique_ptr<Item>(new Image));
		items.push_back(unique_ptr<Item>(new Animation));
		//items.push_back(unique_ptr<Item>(new Audio));
	}

	void Display()
	{
		for (int i = 0; i < items.size(); i++)
			items[i]->DisplayName();
	}
	void Convert(Converter *converter)
	{
		for (int i = 0; i < items.size(); i++)
			items[i]->Convert(converter);
	}
};

class WMVConverter : public Converter
{
public:
	virtual void Convert(Shape *shape)
	{
		cout << "WMV - Shape: " << endl;
	}
	virtual void Convert(Image *image)
	{
		cout << "WMV - Image: " << endl;
	}
	virtual void Convert(Animation *animation)
	{
		cout << "WMV - Animation: " << endl;
	}
};
class PDFConverter : public Converter
{
public:
	virtual void Convert(Shape *shape)
	{
		cout << "PDF - Shape: " << endl;
	}
	virtual void Convert(Image *image)
	{
		cout << "PDF - Image: " << endl;
	}
	//virtual void Convert(Animation *animation)
	//{
	//}
};

class NewPDFConverter : public Converter, public Converter2
{
public:
	virtual void Convert(Shape *shape)
	{
		cout << "New PDF - Shape: " << endl;
	}
	virtual void Convert(Image *image)
	{
		cout << "New PDF - Image: " << endl;
	}

	virtual void Convert(Audio *audio)
	{
		cout << "New PDF - Audio: " << endl;
	}
	//virtual void Convert(Animation *animation)
	//{
	//}
};
void main()
{
	PowerPointSlide ps1;
	ps1.Create();
	ps1.Display();

	WMVConverter wmvconverter;
	ps1.Convert(&wmvconverter); // convert should do converion to wmv

	PDFConverter pdfconverter;
	ps1.Convert(&pdfconverter); // convert should do converion to wmv

	NewPDFConverter newpdfconverter;
	ps1.Convert(&newpdfconverter); // convert should do converion to wmv
}