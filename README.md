## CANalytics

Analyse a CAN Bus data flow in order to detect potential attacks on a vehicule.

### Compilation

make all

### About the dataset

This dataset was used for the the Anomaly Detection in Automobile Track in '2017 Information Security R&D dataset challenge' in South Korea
[https://ocslab.hksecurity.net/Dataset/CAN-intrusion-dataset](https://ocslab.hksecurity.net/Dataset/CAN-intrusion-dataset)

Download the dataset here : [https://www.dropbox.com/sh/b0asam3c45k607a/AAChCVjjIG5v4popd1FdryKSa?dl=0](https://www.dropbox.com/sh/b0asam3c45k607a/AAChCVjjIG5v4popd1FdryKSa?dl=0)

Datas are stored in "/dataset" but those files are overly verbose, that's why we use a set of simple sed commands to remove the verbosity. 

`./formatDataset.sh"`


###### Author

LEFLOCH Thomas <<me@bretzoule.eu>>
