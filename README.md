# home_sensor
�ƒ�Ŏg�p���邱�Ƃ�z�肵��IoT�Z���T�[�B

## Arduino
Arduino LLC�ɂ���ĊJ�������AVR�}�C�R���y�ѓ��o�̓|�[�g������Arduino�V���[�Y�B

Arduino IDE���g�p����C���ꕗ�̃v���O���~���O������g�p���ă}�C�R�����ȒP�ɊJ�����邱�Ƃ��ł���B

### Arduino Scratch code.
�g�p�����\�[�X�R�[�h�B

Arduino IDE���g�p����Arduino�{�̂ɓ]������B

home_sensor/scratch/home_sensor.ino/multi_sensor/multi_sensor.ino

## ELK Stack
ELK�iELK Stack�j�Ƃ́CElastic�Ђ��񋟂���u�f�[�^��M�E���`�v�C�u�f�[�^�ۑ��E��́E�����v�C�u�f�[�^�����v����������I�[�v���\�[�X�̃c�[���Q�ł��B

�����̍\�z��Ubuntu16.04x64�ŃT�[�o���\�z���Ă��܂��B

https://www.elastic.co/jp/products
### Losgatsh
�f�[�^��M�E���`���s���c�[���BTCP�ʐM��t�@�C������̃f�[�^��ǂݍ��݁C�C�ӂ̌`���ɐ��`���ăf�[�^���o�͂���@�\�����B

�f�[�^����M����Linux�T�[�o�̈ȉ��̃f�B���N�g���ɐݒ�t�@�C����z�u����B

```
�g�p����Config

/etc/logstash/conf.d/home_sensor.conf
```
### Elasticsearch
�f�[�^��ۑ��E�����E��͂��邽�߂̃f�[�^�x�[�X�G���W���B

�����ݒ���I����Elasticsearch�T�[�o�ɑ΂��āCcurl�R�}���h��Mapping�iDB�X�L�[�}�j��o�^����B

```
�g�p����Mapping

curl -XPUT SERVERADDR:9200/home_sensor --data @home_sensor.json

Github��elasticsearch�f�B���N�g���ɂ���ucheck_query.json�v��Elasticsearch�ɑ΂��Č����Ƃ���ۂɎg�p�����e�X�g�N�G���B

curl -XGET "http://localhost:9200/home_sensor/_search" -data @check_query.json
```
### Kibana
�f�[�^�x�[�X�ɕۑ����ꂽ�f�[�^��Web�u���E�U��ŉ������邽�߂̃c�[���B

"home_sensor1"���L�[�ɂ��ĉ����̂��߂̃f�[�^�������s���B

```
���ɐݒ�t�@�C���Ȃ��B
```

## docs
�v���_�N�g�̃z�[���y�[�W�̂��߂̃R���e���c�B

�����C���[�W���f�ځB

https://firo838.github.io/home_sensor/

## docker
Docker�̓R���e�i�^���z���̂��߂̃c�[���B

�������B

## �Ō��
�����̃\�[�X�R�[�h�̉��ρE���p�͌l�̐ӔC�̉����p���邱�Ƃ��ł��܂��B

�v���O�����̗��p�C�f�o�C�X�̍쐬�ɂ���Đ����������Ȃ鎖�̂Ȃǂɂ����Ă��ӔC�����܂���B
