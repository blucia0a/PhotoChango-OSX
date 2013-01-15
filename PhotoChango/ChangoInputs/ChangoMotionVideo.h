class ChangoMotionVideo : public ChangoInput{
    Mahalo *m;
    ChangoGenerator *chango;
public:
    /*Constructor should run the input handler and return to end main()*/
    ChangoMotionVideo(ChangoGenerator *chan, Mahalo *M);
    virtual void highlight(CvPoint p1, CvPoint p2);
};
