namespace engine
{
	struct Screen
	{
	public:
		unsigned int getWidth();
		unsigned int getHeight();
		void setWidth(unsigned int width);
		void setHeight(unsigned int height);

	private:
		unsigned int width;
		unsigned int height;
	};
}
