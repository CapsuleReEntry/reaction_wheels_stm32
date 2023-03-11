class Motor {
	public:
		virtual errcode hardwareInitialization;
    virtual void moveControle();
	  virtual void MoveRightSide();
	private:
	
};

class MoveControl {

};

class HardwearInit {

}

class Motor {
exemplar MoveControl
exemplar HardwearInit
}