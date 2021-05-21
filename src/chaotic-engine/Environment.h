namespace engine
{
	struct Environment
	{
	public:
		double getDeltaTime();
		void setDeltaTime(double time);

	private:
		double deltaTime;

	};
}