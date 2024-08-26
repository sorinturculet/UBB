from domain.StudentValidator import *
from domain.SubjectValidator import *
from repository.StudentRepo import *
from repository.SubjectRepo import *
from repository.MarksRepo import *
from service.StudentService import *
from service.SubjectService import *
from service.MarkService import *
from UI.console import Console

studentrepo=StudentRepository()
subjectrepo=SubjectRepository()
markrepo=EventRepository()
studentvalidator=StudentValidator()
subjectvalidator=SubjectValidator()
controller_student=StudentController(studentrepo,studentvalidator)
controller_subject=SubjectController(subjectrepo,subjectvalidator)
controller_mark=MarkController(markrepo,studentrepo,subjectrepo)
console=Console(controller_student,controller_subject,controller_mark)
console.run()