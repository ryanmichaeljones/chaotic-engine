namespace engine
{
	struct Environment
	{
	public:
		float getDeltaTime();
		void setDeltaTime(float time);

	private:
		float deltaTime;

	};
}