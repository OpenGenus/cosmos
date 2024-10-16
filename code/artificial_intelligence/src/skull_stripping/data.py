#downloading necessary files
!wget --header 'Host: fcp-indi.s3.amazonaws.com' --user-agent 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:87.0) Gecko/20100101 Firefox/87.0' --header 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' --header 'Accept-Language: en-US,en;q=0.5' --referer 'http://preprocessed-connectomes-project.org/' --header 'Upgrade-Insecure-Requests: 1' 'https://fcp-indi.s3.amazonaws.com/data/Projects/RocklandSample/NFBS_Dataset.tar.gz' --output-document 'NFBS_Dataset.tar.gz'
!wget --header 'Host: doc-08-2g-docs.googleusercontent.com' --user-agent 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:87.0) Gecko/20100101 Firefox/87.0' --header 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' --header 'Accept-Language: en-US,en;q=0.5' --referer 'https://drive.google.com/' --header 'Cookie: AUTH_9k7m8g8qrj7at7i0b1sl7f8s8gafrr77_nonce=fchj71prkosgs' --header 'Upgrade-Insecure-Requests: 1' 'https://doc-08-2g-docs.googleusercontent.com/docs/securesc/5baff4djp5n2ak1832to2m6lltldb4gl/lld851i2e7pqe774volddlu45niullkl/1621202400000/00677992938550103544/12785117600840412092/1N1Qx-R5tLCX5EhXPoPdyg6YvEkDtf-cD?e=download&authuser=0&nonce=fchj71prkosgs&user=12785117600840412092&hash=0lccq4nigav75jop1timeo66ook4s4q1' --output-document 'ANTs-28-03-2019.7z'
!wget --header 'Host: doc-00-48-docs.googleusercontent.com' --user-agent 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:87.0) Gecko/20100101 Firefox/87.0' --header 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8' --header 'Accept-Language: en-US,en;q=0.5' --referer 'https://drive.google.com/' --header 'Cookie: AUTH_9k7m8g8qrj7at7i0b1sl7f8s8gafrr77=12785117600840412092|1621202400000|urd0fgd911j76j00e1g3sfrlmgno1864' --header 'Upgrade-Insecure-Requests: 1' 'https://doc-00-48-docs.googleusercontent.com/docs/securesc/5baff4djp5n2ak1832to2m6lltldb4gl/andn6io8vgl8gpaplbqeg39eum6c4c3k/1621202475000/15988357211529156717/12785117600840412092/1y8N6JpKhyoLDQcscdudwMCgqubjQyfd1?e=download&authuser=0' --output-document 'T1w_MRI_test_data.zip'
!unzip '/content/T1w_MRI_test_data.zip'

#for handling MRI images
!pip install nipype
!pip install antspyx
!pip install nilearn
!pip install SimpleITK

#for segmentation
!pip install q keras==2.3.1
!pip install segmentation_models

#for running ANTS library in colab
!7z x ANTs-28-03-2019.7z
!cp bin/* /usr/local/bin

#Extracting nfbs dataset
import tarfile
file = tarfile.open('/content/NFBS_Dataset.tar.gz')
file.extractall('/content/')
file.close()

print('Each folder contains..')
print(os.listdir('/content/NFBS_Dataset/A00028185'))
img=nib.load('/content/NFBS_Dataset/A00028185/sub-A00028185_ses-NFB3_T1w.nii.gz')
print('Shape of image=',img.shape)

#storing the address of 3 types of files
import os
brain_mask=[]
brain=[]
raw=[]
for subdir, dirs, files in os.walk('/content/NFBS_Dataset'):
    for file in files:
        #print os.path.join(subdir, file)y
        filepath = subdir + os.sep + file

        if filepath.endswith(".gz"):
          if '_brainmask.' in filepath:
            brain_mask.append(filepath)
          elif '_brain.' in filepath:
            brain.append(filepath)
          else:
            raw.append(filepath)


#creating a dataframe for ease of use..
data=pd.DataFrame({'brain_mask':brain_mask,'brain':brain,'raw':raw})
data.head()
