

class ChangoLightVideo : public ChangoInput{
    Mahalo *m;
    ChangoGenerator *chango;
public:
    /*Constructor should run the input handler and return to end main()*/
    ChangoLightVideo(ChangoGenerator *chan, Mahalo *M);
    virtual void highlight(CvPoint p1, CvPoint p2);
    virtual ~ChangoLightVideo();
};
