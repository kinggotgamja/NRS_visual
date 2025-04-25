Step1. "view_ur10.launch" 파일을 실행하면 UR10 Model이 로드됩니다.
Step2. "rosrun NRS_VirUR_cmd"을 하면 "rtde_handarm/Yoon_UR10e_main" 노드에서 
        발행된 실시간 joint angle 이 가상환경상의 로봇 조인트의 cmd로 전달됩니다. 
        (실시간 joint angle은 "UR10_Jangle"의 topic으로 발행)

참고
: "src/NRS_VirUR_cmd.cpp" 파일을 확인해 보면 자세한 내용을 알 수 있습니다.
